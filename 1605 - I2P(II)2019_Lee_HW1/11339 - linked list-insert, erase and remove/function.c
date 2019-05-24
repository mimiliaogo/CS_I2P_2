#include <stdio.h>
#include <stdlib.h>
#include "function.h"


Node* createnode(unsigned short val)//insert before
{
    Node* np = (Node*) malloc(sizeof(Node));
    np->val = val;
    np->next = NULL;
    np->prev = NULL;
    return np;
}

void do_I(Node **head,size_t pos,unsigned short val)
{
    int cnt=0;
    Node *np, *cur, *node;
    np = createnode(val);
    cur = *head;
    if (*head==NULL) {
        *head = np;
        return;
    }
    while (cur->next!=NULL || pos==cnt) {
        if (cnt==pos) {//insert before node
            node = cur;
            np->next = node;
            if (node->prev==NULL) *head = np;
            else {
                np->prev = node->prev;
                np->prev->next = np;
            }
            node->prev = np;
            return;
        }
        cur = cur->next;
        cnt++;
    }
    //insert at the last
    cur->next = np;
    np->prev = cur;

}
void removeNode(Node **head, Node* node)
{
	if (node->prev==NULL && node->next==NULL) {//only one node in t
        *head = NULL;
    }
    else if (node->prev==NULL) {//remove the beginning
        *head = node->next;
        node->next->prev = NULL;
    }
    else if(node->next==NULL) {//remove the end
        node->prev->next = NULL;
    }
    else {//remove the middle
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
}

void do_E(Node **head,size_t begin_pos,size_t end_pos)
{
    int count = 0;
    Node* cur = *head;
    Node* tmp;
    if (begin_pos==end_pos) return;
    else {
        while (cur!=NULL) {
            if (count==begin_pos) {
                while (cur!=NULL && count!=end_pos) {

                    tmp = cur;
                    cur = cur->next;
                    //must be front of the remove function, for remove will kill the cur node
                    removeNode(head, tmp);

                    count++;
                }
                return;
            }
            cur = cur->next;
            count++;
        }
    }
}
void do_P(Node  *head,size_t pos)
{
    Node* cur;
    cur = head;
    int count = 0;
    if (head==NULL) return;
    while (cur->next!=NULL) {
        if (count==pos)  {
            printf("%d ", cur->val);
            return;
        }
        cur = cur->next;
        count++;
    }
    printf("%d ", cur->val);

}


void do_R(Node **head,unsigned short val)
{
    Node* cur;
    Node* tmp;
    cur = *head;
    while (cur!=NULL) {
        tmp = cur;
        cur = cur->next;
        if (tmp->val == val) {
            removeNode(head, tmp);
        }
    }
}
void do_S(Node  *head)
{
    Node *cur;
    cur = head;
    while (cur!=NULL) {
        printf("%hu ", cur->val);
        cur = cur->next;
    }
}
