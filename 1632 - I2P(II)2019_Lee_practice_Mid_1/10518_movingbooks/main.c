#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node {
    int data;
    struct _node* next;
    struct _node* prev;
} Node;
int NB;
Node* createList(int data) {//dll list
    Node* head= (Node*) malloc(sizeof(Node));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    if (data==NB-1)  return head;
    head->next = createList(data+1);
    head->next->prev = head;
    return head;
}
void showNode(Node* head) {
    Node* tmp;
    for (tmp = head; tmp!=NULL; tmp = tmp->next ) {
        printf("%d ", tmp->data);
    }
    printf("\n");
}
Node* moveA(Node* head, Node* A)//take out A from the list
{
    if (A->prev==NULL&&A->next==NULL) return NULL;
    if (A==head) {
        head->next->prev = NULL;
        head = head->next;
    }
    else {
        A->prev->next = A->next;
        if (A->next!=NULL) A->next->prev = A->prev;
    }
    return head;
}
Node* removeNode(Node* head, int data) {
    if (head==NULL) return NULL;
    Node* cur = head;
    while (cur->data!=data && cur->next!=NULL) cur = cur->next;
    if (cur->data!=data) return head;
    head = moveA(head, cur);
    free(cur);
    return head;
}

Node* beforeB(Node* head, Node* A, Node* B)
{
    if (B==head) {
        head->prev = A;
        A->next = head;
        head = A;
    }
    else {
        A->next = B;
        A->prev = B->prev;
        B->prev->next = A;
        B->prev = A;
    }
    return head;
}
Node* afterB(Node* head, Node* A, Node* B)
{
    if (B->next==NULL) {//the last one
        B->next = A;
        A->prev = B;
        A->next = NULL;
    }
    else head = beforeB(head, A, B->next);
    return head;
}

Node* moveAonB(Node* head, int a, int b) {
    Node* A, *B;
    A = head;
    B = head;
    while (A->data!=a && A->next!=NULL) A = A->next;
    while (B->data!=b && B->next!=NULL) B = B->next;
    if (A->data!=a||B->data!=b) return head;
    head = moveA(head, A);
    head = afterB(head, A, B);
    return head;
}
Node* moveAunderB(Node* head, int a, int b) {
    Node* A, *B;
    A = head;
    B = head;
    while (A->data!=a && A->next!=NULL) A = A->next;
    while (B->data!=b && B->next!=NULL) B = B->next;
    if (A->data!=a||B->data!=b) return head;
    head = moveA(head, A);
    head = beforeB(head, A, B);
    return head;
}
int main()
{
    char cmd[20];
    int a, b;
    int del;
    Node* head = NULL;
    scanf("%d", &NB);
    head = createList(0);
    while (1) {
       scanf("%s", cmd);
       if (strncmp(cmd, "move", 4)==0) {
            scanf("%d %s %d", &a, cmd, &b);
            if (strncmp(cmd, "on", 2)==0) {
                if (a!=b && a<NB && b<NB) {
                    head = moveAonB(head, a, b);
                }
            } else {
                if (a!=b && a<NB && b<NB){
                    head = moveAunderB(head, a, b);
                }
            }
       }
       else if (strncmp(cmd, "exit", 4)==0) {
            showNode(head);
            break;
       }
       else {
            scanf("%d", &del);
            if (del<NB) {
                head = removeNode(head, del);
            }
       }
    }
}
