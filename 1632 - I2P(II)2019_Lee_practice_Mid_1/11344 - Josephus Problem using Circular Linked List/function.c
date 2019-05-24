#include<stdio.h>
#include "function.h"

Node* create(int n)
{
    int i;
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 1;
    Node* cur = head;
    for (i=2; i<=n; i++) {
        cur->next = (Node*) malloc(sizeof(Node));
        cur = cur->next;
        cur->data = i;
    }
    cur->next = head;

    return head;

}
void josephus(int m,Node *head)
{
    Node* tmp = head;
    Node* deltmp = NULL;
    int i;
    while (tmp->next!=tmp) {//more than one
        i = m;
        while (i>2) {
            tmp = tmp->next;
            i--;
        }//now tmp is the node 'before' we want to remove
        deltmp = tmp->next;
        tmp->next = deltmp->next;
        printf("%d ", deltmp->data);
        tmp = tmp->next;
        free(deltmp);
    }
    printf("%d\n", tmp->data);



}
//testing
//void showNode(Node* head)
//{
//    if (head==NULL) printf("\n");
//    else {
//        printf("%d ", head->data);
//        showNode(head->next);
//    }
//}
