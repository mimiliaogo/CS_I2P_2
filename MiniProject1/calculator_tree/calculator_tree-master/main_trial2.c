#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "lex.h"
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


void statement(void);
void expr(void);
void term(void);
void factor(void);

void statement(void)
{
    if (match(END)) {
        advance();
        // nothing
    } else {
        expr();
        match(END);
        advance();
    }
}
void expr(void)
{
    term();
    while (match(ADDSUB)){
        printf("ADDSUB: %s\n", getLexeme());
        advance();
        term();
    }
}
void term(void) {
    factor();
    while (match(MULDIV)) {
        printf("MULDIV: %s\n", getLexeme());
        advance();
        factor();
    }
}
void factor(void)
{
    if (match(INT)) {
        printf("INT: %s\n", getLexeme());
        advance();
    } else if (match(ADDSUB)) {
        printf("ADDSUB: %s\n", getLexeme());
        advance();
        if (match(INT)) {
            printf("INT: %s\n", getLexeme());
            advance();
        } else if (match(ID)) {
            printf("ID: %s\n", getLexeme());
            advance();
        }
    } else if (match(ID)) {
        printf("ID: %s\n", getLexeme());
        advance();
        if (match(ASSIGN)) {
            printf("ASSIGN: %s\n", getLexeme());
            advance();
            expr();
        }
    } else if (match(LPAREN)) {
        printf("LPAREN: %s\n", getLexeme());
        advance();
        expr();
        if (match(RPAREN)) {
            printf("RPAREN: %s\n", getLexeme());
            advance();
        } else {
            printf("Parenthesis mismatched\n");
        }
    }
}

int main(void)
{
    statement();
    return 0;
}


