#include <stdio.h>
#include "function.h"

void rotateList(Node** head,int k)
{
    Node* tmp = *head;
    if (k==0 || *head==NULL) return;
    else {
        rotateList(head, k-1);
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = *head;
        *head = (*head)->next;
        tmp->next->next = NULL;

    }
}
