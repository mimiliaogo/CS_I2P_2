#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct node{
        int data;
        struct node *next;
} Node;
Node* create(int n);
void josephus(int m,Node *head);

#endif
