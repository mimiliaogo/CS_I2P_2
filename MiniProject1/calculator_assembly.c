#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#ifndef __LEX__
#define __LEX__
#define MAXLEN 256
//add AND XOR OR
//ADD EOF
typedef enum {UNKNOWN, END, INT, ID, AND, XOR, OR, ADDSUB, MULDIV, ASSIGN, _EOF,
LPAREN, RPAREN} TokenSet;

extern int match (TokenSet token);
extern void advance(void);
extern char* getLexeme(void);
#endif // __LEX__

int Isend;
int IDnum;
int position;
int r[10]={0};//record the use of the register
/*
Something like Python
>> y = 2
>> z = 2
>> x = 3*y + 4/(2*z)

*/

/*
the only type: integer
everything is an expression
  statement   := END | expr END
  expr        := term expr_tail
  expr_tail   := ADDSUB term expr_tail | NIL
  term        := factor term_tail
  term_tail := MULDIV factor term_tail | NIL
  factor      := INT | ADDSUB INT | ADDSUB ID | ID ASSIGN expr | ID | LPAREN expr RPAREN
*/

#define TBLSIZE 65535
typedef struct {
	char name[MAXLEN];
	int val;
	//judge whether it is new
	int Isnew;
} Symbol;
Symbol table[TBLSIZE];
int sbcount = 0;

typedef struct _Node {
	char lexeme[MAXLEN];
	TokenSet token;
	int val;
	struct _Node *left, *right;
} BTNode;

void statement(void);
//ADD 3 GRAMMAR
BTNode* ORexpr(void);
BTNode* XORexpr(void);
BTNode* ANDexpr(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);
int getval(void);
int setval(char*, int);
static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
static char lexeme[MAXLEN];

typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NAN} ErrorType;
void error(ErrorType errorNum);

/* create a node without any child */
BTNode* makeNode(TokenSet tok, const char *lexe)
{
	BTNode *node = (BTNode*) malloc(sizeof(BTNode));
	strcpy(node->lexeme, lexe);
	node->token= tok;
	node->val = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//add AND XOR OR
TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // 忽略空白字元

    if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i<MAXLEN) {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    } else if (c == '+' || c == '-') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ADDSUB;
    } else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    }else if (c == '^') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return XOR;
    }else if (c == '|') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return OR;
    }else if (c == '&') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return AND;
    }else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    } else if (c == '=') {
        strcpy(lexeme, "=");
        return ASSIGN;
    } else if (c == '(') {
        strcpy(lexeme, "(");
        return LPAREN;
    } else if (c == ')') {
        strcpy(lexeme, ")");
        return RPAREN;
    } else if (isalpha(c) || c == '_') {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isalpha(c) || isdigit(c) || c == '_') {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return ID;
    } else if (c==EOF) {
        return _EOF;
    } else {
        return UNKNOWN;
    }
}

void advance(void)
{
    lookahead = getToken();
}

int match(TokenSet token)
{
    if (lookahead == UNKNOWN) advance();
    return token == lookahead;
}

char* getLexeme(void)
{
    return lexeme;
}



/* clean a tree */
void freeTree(BTNode *root)
{
	if (root!=NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

/* print a tree by pre-order */
void printPrefix(BTNode *root)
{
	if (root != NULL) {
		printf("%s ", root->lexeme);
		printPrefix(root->left);
		printPrefix(root->right);
	}
}


//return the position where the result of the evaluation is in
int evaluateTreePosition(BTNode *root)
{
	int retval = 0, lv, rv;
    int lvp, rvp;
    int mempos;//position in memory
	int i=0;
	int j=0;
	if (root != NULL) {
		switch (root->token) {
		case ID:
		    i=0;
		    j=0;
		    while (r[i]!=0) i++;
		    position = i;
			r[position]=1;
			while (j<sbcount) {
                if (strcmp(root->lexeme, table[j].name)==0) {
                    mempos = 4*j;
                    break;
                } else {
                    j++;
                }
            }
            //FIRST time appear in the right
            if(table[j].Isnew==1) error(NOTFOUND);
            printf("MOV r%d [%d]\n", position, mempos);
            break;
		case INT://find an empty register
		    i=0;
			while (r[i]!=0) i++;
			position = i;
			r[position]=1;
			printf("MOV r%d %s\n", position, root->lexeme);
			break;
		case ASSIGN:
		case ADDSUB:
		case MULDIV:
        case AND:
        case XOR:
        case OR:
			if (strcmp(root->lexeme, "+") == 0) {
                lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("ADD r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}

			else if (strcmp(root->lexeme, "-") == 0) {
                lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("SUB r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}

			else if (strcmp(root->lexeme, "*") == 0) {
                lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("MUL r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}

			else if (strcmp(root->lexeme, "/") == 0) {
				lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("DIV r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}//ADD & | ^
			else if (strcmp(root->lexeme, "&") == 0) {
				lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("AND r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}
			else if (strcmp(root->lexeme, "^") == 0) {
				lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("XOR r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}
			else if (strcmp(root->lexeme, "|") == 0) {
				lvp = evaluateTreePosition(root->left);
                rvp = evaluateTreePosition(root->right);
                printf("OR r%d r%d\n", lvp, rvp);
                position = lvp;//the value position on the register
                r[rvp]= 0;//Nothing
                r[lvp]= 1;//value in it
			}
			else if (strcmp(root->lexeme, "=") == 0) {
				//retval = setval(root->left->lexeme, rv); //put the value of the right equation to the left ID
                rvp = evaluateTreePosition(root->right);
                j=0;
                while (j<sbcount) {
                if (strcmp(root->left->lexeme, table[j].name)==0) {
                    mempos = 4*j;
                    break;
                } else {
                        j++;
                    }
                }
                printf("MOV [%d] r%d\n", mempos, rvp);
                table[j].Isnew=0;//have value
                r[rvp]=0;
			}

			break;
		default:
			position = 0;
		}
	}
	return position;
}

int getval(void)//find the value of the old ID or create a new one
{
	int i, retval, found;

	if (match(INT)) {
		retval = atoi(getLexeme());
	} else if (match(ID)) {
		i = 0;
		found = 0;
		retval = 0;
		while (i<sbcount && !found) {
			if (strcmp(getLexeme(), table[i].name)==0) {
				retval = table[i].val;
				found = 1;
				break;
			} else {
				i++;
			}
		}
		if (!found) {
			if (sbcount < TBLSIZE) {

				strcpy(table[sbcount].name, getLexeme());
				table[sbcount].val = 0;
				table[sbcount].Isnew=1;
				sbcount++;
			} else {
				error(RUNOUT);
			}
		}
	}
	return retval;
}

int setval(char *str, int val)
{
	int i, retval = 0;
	i = 0;
	while (i<sbcount) {
		if (strcmp(str, table[i].name)==0) {
			table[i].val = val;
			retval = val;
			break;
		} else {
			i++;
		}
	}
	return retval;
}

//  expr        := term expr_tail
//  expr_tail   := ADDSUB term expr_tail | NIL
BTNode* expr(void)
{
	BTNode *retp, *left;
	retp = left = term();
	while (match(ADDSUB)) { // tail recursion => while
		retp = makeNode(ADDSUB, getLexeme());
		advance();
		retp->right = term();
		retp->left = left;
		left = retp;
	}
	return retp;
}
//or
BTNode* ORexpr(void)
{
	BTNode *retp, *left;
	retp = left = XORexpr();
	while (match(OR)) { // tail recursion => while
		retp = makeNode(OR, getLexeme());
		advance();
		retp->right = XORexpr();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* XORexpr(void)
{
	BTNode *retp, *left;
	retp = left = ANDexpr();
	while (match(XOR)) { // tail recursion => while
		retp = makeNode(XOR, getLexeme());
		advance();
		retp->right = ANDexpr();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* ANDexpr(void)
{
	BTNode *retp, *left;
	retp = left = expr();
	while (match(AND)) { // tail recursion => while
		retp = makeNode(AND, getLexeme());
		advance();
		retp->right = expr();
		retp->left = left;
		left = retp;
	}
	return retp;
}

//  term        := factor term_tail
//  term_tail := MULDIV factor term_tail | NIL
BTNode* term(void)
{
	BTNode *retp, *left;
	retp = left = factor();
	while (match(MULDIV)) { // tail recursion => while
		retp = makeNode(MULDIV, getLexeme());
		advance();
		retp->right = factor();
		retp->left = left;
		left = retp;
	}
	return retp;
}
//change expr to orexpr
BTNode* factor(void)
{
	BTNode* retp = NULL;
	char tmpstr[MAXLEN];

	if (match(INT)) {
		retp =  makeNode(INT, getLexeme());
		retp->val = getval();
		advance();
	} else if (match(ID)) {
	    IDnum++;

		BTNode* left = makeNode(ID, getLexeme());
		left->val = getval();//key to know whether it is new
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ASSIGN)) {
		    //IF the id in front of the '=' is more than one
            if(IDnum>1) error(NOTNUMID);
			retp = makeNode(ASSIGN, getLexeme());
			advance();
			retp->right = ORexpr();
			retp->left = left;
		} else {
		    //if it is new and not in the right of assign
			retp = left;
		}
	} else if (match(ADDSUB)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(ADDSUB, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			error(NOTNUMID);
		}
	} else if (match(LPAREN)) {
		advance();
		retp = ORexpr();
		if (match(RPAREN)) {
			advance();
		} else {
			error(MISPAREN);
		}
	} else {
		error(NOTNUMID);
	}
	return retp;
}

void error(ErrorType errorNum)
{
	switch (errorNum) {
	case MISPAREN:
//		fprintf(stderr, "Mismatched parenthesis\n");
        printf("EXIT 1\n");
		break;
	case NOTNUMID:
//		fprintf(stderr, "Number or identifier expected\n");
		printf("EXIT 1\n");
		break;
	case NOTFOUND:
//		fprintf(stderr, "%s not defined\n", getLexeme());
        printf("EXIT 1\n");
		break;
	case RUNOUT:
//		fprintf(stderr, "Out of memory\n");
        printf("EXIT 1\n");
		break;
	case NAN:
//		fprintf(stderr, "Not a number\n");
        printf("EXIT 1\n");
	}
	Isend=1;
	exit(0);
}

void statement(void)
{
	BTNode* retp;
	int val;
    int i;
    if (match(_EOF)) {
        printf("MOV r0 [0]\n");
        printf("MOV r1 [4]\n");
        printf("MOV r2 [8]\n");
        printf("EXIT 0\n");
        Isend=1;
        return;
    }
	if (match(END)) {
//		printf(">> ");
		advance();
	} else {
		retp = ORexpr();
        if (retp->token!=ASSIGN) error(NOTFOUND);
		if (match(END)) {
            position = evaluateTreePosition(retp);
            val= evaluateTree(retp);
//			printPrefix(retp);
//			printf("\n");
			freeTree(retp);
//			//clean the register
//            for(i=0; i<8; i++) r[i] = 0;
//			printf(">> ");
			advance();
		}
	}

}
//check the divider != 0
int evaluateTree(BTNode *root)
{
	int retval = 0, lv, rv;
	if (root != NULL) {
		switch (root->token) {
		case ID:
		case INT:
			retval = root->val;
			break;
		case ASSIGN:
		case ADDSUB:
		case MULDIV:
			lv = evaluateTree(root->left);
			rv = evaluateTree(root->right);
			if (strcmp(root->lexeme, "+") == 0)
				retval = lv + rv;
			else if (strcmp(root->lexeme, "-") == 0)
				retval = lv - rv;
			else if (strcmp(root->lexeme, "*") == 0)
				retval = lv * rv;
			else if (strcmp(root->lexeme, "/") == 0) {
				if (rv==0)
					error(NAN);
				else
					retval = lv / rv;
			} else if (strcmp(root->lexeme, "=") == 0)
				retval = setval(root->left->lexeme, rv);
			break;
		default:
			retval = 0;
		}
	}
	return retval;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    //set the initial variable of x, y, z in memory
    for (int i=0; i<3; i++) {
        table[i].name[0] = 'x'+i;
        table[i].name[1] = '\0';
        table[i].Isnew = 0;
        sbcount++;
    }

//	printf(">> ");
	while (Isend==0) {
        IDnum=0;
		statement();
	}
	return 0;
}

/*
int main(void)
{
    TokenSet tok;
    tok = getToken();
    while (tok != END) {
        printf("%d: %s\n", tok, getLexeme());
        tok = getToken();
    }
    return 0;
}
*/
