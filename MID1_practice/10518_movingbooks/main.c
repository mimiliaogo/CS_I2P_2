#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node {
    int data;
    struct _node* next;
    struct _node* prev;
} Node;
int NB;
Node* createList(int data) {
    Node* head;
	head =  (Node*) malloc(sizeof(Node));
    head->data = data;
	head->prev = NULL;
	head->next = NULL;
    if (data==NB-1) return head;

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
Node* removeNode(Node* head, int data) {
    Node *tmp;
    tmp = head;

    while (tmp->data!=data && tmp->next!=NULL) tmp = tmp->next;
    if (tmp->data!=data) return head;

    //now tmp is the node we want to remove
    if (tmp==head&&tmp->next==NULL) {//only one node
        head = NULL;
    }
    else if (tmp==head) {//remove head
        tmp->next->prev = NULL;
        head = tmp->next;
    } else if (tmp->next==NULL) {//remove the least
        tmp->prev->next = NULL;
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    free(tmp);
    return head;

}
Node* moveA(Node* head, Node* A)
{
    if (A==head) {//remove head
        A->next->prev = NULL;
        head = A->next;
    } else if (A->next==NULL) {//remove the least
        A->prev->next = NULL;
    } else {
        A->prev->next = A->next;
        A->next->prev = A->prev;
    }
    return head;

}
Node* beforeB(Node* head, Node* A, Node* B)
{
    if (B==head) {
        A->prev = NULL;
        A->next = head;
        head->prev = A;
        head = A;
    } else {
        A->prev = B->prev;
        A->next = B;
        B->prev->next = A;
        B->prev = A;
    }

    return head;
}
void afterB(Node* A, Node* B)
{
    if (B->next==NULL) {//at the least
        B->next = A;
        A->next = NULL;
        A->prev = B;
    } else {
        A->prev = B;
        A->next = B->next;
        B->next->prev = A;
        B->next = A;
    }


}

Node* moveAonB(Node* head, int a, int b) {
    Node* A, *B;
    A = head;
    B = head;
    while (A->data!=a && A->next!=NULL) A = A->next;
    while (B->data!=b && B->next!=NULL) B = B->next;
    if (A->data!=a||B->data!=b) return head;
    head = moveA(head, A);
    afterB(A, B);
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
