/* This program construct a syntax tree from an infix Boolean expression.
   The expression has no parenthesis, and no error checking.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6
char expr[MAXEXPR];
int pos;

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM]="ABCD&|";

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

/* create a node without any child.*/
BTNode* makeNode(char c){
    int i;
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    for (i = 0; i< NUMSYM; i++)
        if (c==sym[i]) node->data = i;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* parse an infix expression and generate a syntax tree. */
BTNode* EXPR(){
    char c;
    BTNode *node = NULL, *right=NULL;

    if (pos>=0) {   // if the expression has length > 1.
        c = expr[pos--];  // parse from the end of expression.
        if (c>= 'A' && c<='D')   // 1. the VAR case
            right = makeNode(c);

        if (pos>0) {// 2. the EXPR OP ID case
            c = expr[pos];
            if (c=='&' || c=='|'){
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            } else node = right; // 1. EXPR = ID
        } else
            node = right; // 1. EXPR = ID
    }
    return node;
}

int main(){
    gets(expr);
    pos = strlen(expr)-1;
    BTNode *root = EXPR();
    printPrefix(root);
    freeTree(root);
    return 0;
}
