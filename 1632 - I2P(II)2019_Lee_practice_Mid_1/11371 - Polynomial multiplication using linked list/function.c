#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void printNode(Node* head)//the function which will print the output
{
    if (head==NULL) return;
    else {
        if (head->data!=0) {
            printf("%ld %d ", head->data, head->power);
        }
        printNode(head->next);
    }
}

Node* makeNode(int data, int power) {
    Node* np;
    np = (Node*)malloc(sizeof(Node));
    np->data = data;
    np->power = power;
    np->next = NULL;
    np->prev = NULL;
    return np;
}
Node* create() //create polynomial linked list
{
    Node* head;
    int data, power;
    scanf("%d%d", &data, &power);
    head = makeNode(data, power);
    if (power==0) return head;
    head->next = create();
    head->next->prev = head;
    return head;
}
void destroy(Node *node)//destroy polynomial linked list
{
    if (node!=NULL) {
        destroy(node->next);
        free(node);
    }
}

Node* multiple(Node* p1, Node* p2) //input two polynomial linked list and return the result
{
    int data, power;
    Node* p3=NULL;
    Node* t1, *t2, *t3, *t4;
    for (t1=p1; t1!=NULL; t1 = t1->next) {
        for (t2=p2; t2!=NULL; t2 = t2->next) {
            data = t1->data*t2->data;
            power = t2->power+t1->power;
            if (p3==NULL) p3 = makeNode(data, power);
            else {
                for (t3=p3; t3!=NULL; t3 = t3->next) {
                    if (t3->power==power) {
                        t3->data +=data;
                        break;
                    }
                    else if (t3->power<power) {
                        t4 = makeNode(data, power);

                        t4->next = t3;
                        t4->prev = t3->prev;
                        if (t3->prev!=NULL) t3->prev->next = t4;
                        t3->prev = t4;
                        break;
                    }
                    else {
                        if (t3->next==NULL) {
                            t4 = makeNode(data, power);
                            t3->next = t4;
                            t4->prev = t3;
                            break;
                        }
                    }
                }
            }
        }
    }
    return p3;

}
