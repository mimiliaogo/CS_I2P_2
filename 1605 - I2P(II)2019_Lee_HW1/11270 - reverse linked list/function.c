#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList()
{
        int data;
    Node* head;
    scanf("%d", &data);
    if (data==-1) return NULL;//stop
    head = (Node*) malloc(sizeof(Node));
    head->data = data;
    head->next = createList();
    return head;


}
//Node* createList()
//{
//    Node *np, *cur;
//    Node* head = NULL;
//    int val;
//
//    while (1) {
//        scanf("%d", &val);
//        if (val==-1) break;
//        np = (Node*) malloc(sizeof(Node));
//        np->data = val;
//        np->next = NULL;
//        if (head==NULL) {
//            head = np;
//            cur = head;
//        }
//        else {
//            cur->next = np;
//            cur = cur->next;
//        }
//    }
//    return head;
//
//}
//Node* reverse(Node* head)
//{
//    Node* cur;
//    Node* pre;
//    Node* nxt;
//    cur = head;
//    pre = NULL;
//    while (cur!=NULL) {
//        nxt = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = nxt;
//    }
//    head = pre;
//    return head;
//}

Node* reverse(Node* p)
{
    Node* head;
    Node* cur;
    if (p==NULL) return NULL;
    if (p->next==NULL) return p;
    else {
        cur = p->next;
        head = reverse(p->next);
        cur->next = p;
        p->next = NULL;
    }
    return head;
}




