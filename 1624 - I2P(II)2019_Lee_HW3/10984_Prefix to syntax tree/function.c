#include <stdio.h>
#include "function.h"

Node* newNode(char c)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void constructTree(Node** head)
{
    char c;
    c = getchar();
    if (c=='|'||c=='&') {
        *head = newNode(c);
        constructTree(&((*head)->left));
        constructTree(&((*head)->right));
    }
    else if (c>='A'&&c<='D') {
        *head = newNode(c);
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
}


