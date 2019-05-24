#include <stdio.h>
#include "function.h"
BTNode* EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;
    if (pos>=0) {
        right = FACTOR();
        if (pos>0) {
            c = expr[pos];
            if (c=='&'||c=='|') {
                pos--;
                node = makeNode(c);
                node->right = right;
                node->left = EXPR();
            }
            else node = right;
        } else node = right;
    }
    return node;
}
BTNode* FACTOR()
{
    BTNode* node = NULL;
    char c;
    if (pos>=0) {
        c = expr[pos--];
        if (c<='D'&&c>='A') {
            node = makeNode(c);
        }
        else if (c==')') {
            node = EXPR();
            pos--;
        }
    }
    return node;

}
BTNode* makeNode(char c)
{
    BTNode* node;
    int i;
    node = (BTNode*) malloc(sizeof(BTNode));
    for (i=0; i<6; i++) {
        if (c==sym[i]) node->data = i;
    }
    node->left= NULL;
    node->right = NULL;
    return node;

}
