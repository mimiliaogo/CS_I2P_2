

#include <stdio.h>
#include <stdlib.h>
#include "function.h"



BTNode* EXPR()
{
    char c;
    BTNode* node, *right;
    if (pos>=0) {
        right = FACTOR();
        if (pos>0) {
            c = expr[pos];
            if (c=='&'||c=='|') {
                node = makeNode(c);
                pos--;
                node->right = right;
                node->left = EXPR();
            }
            else node = right;
        }
        else node = right;
    }
    return node;
}
BTNode* FACTOR()
{
    char c;
    BTNode* node;
    c = expr[pos--];
    if (c>='A'&&c<='D') {
        node = makeNode(c);
    }
    else if (c==')') {
        node = EXPR();
        pos--;
    }


    return node;
}
BTNode* makeNode(char c)
{
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));
    int i;
    for (i=0; i<6; i++) {
        if (c==sym[i]) node->data = i;
    }
    node->right = NULL;
    node->left = NULL;
    return node;

}
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

