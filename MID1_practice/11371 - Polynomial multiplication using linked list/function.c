#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void printNode(Node* head)//the function which will print the output
{
    if (head==NULL) return;//to the tail of the list
    else {
        if (head->data!=0) {
            printf(" %ld %d", head->data, head->power);
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
    Node* t1, *t2, *t3, *t4;
    Node* p3 = NULL;
    int power, data;
    for (t1=p1; t1!=NULL; t1 = t1->next) {
        for (t2=p2; t2!=NULL; t2 = t2->next) {
            data = (t1->data) * (t2->data);
            power = t1->power + t2->power;
            //insert the result to p3
            if (p3==NULL) {
                p3 = makeNode(data, power);
            } else {//p3!=NULL
                for (t3=p3; t3!=NULL; t3 = t3->next) {
                    if (t3->power==power) {
                        t3->data+=data;
                        break;
                    }
                    else if (t3->power<power) {//insert before t3
                        t4 = makeNode(data, power);
                        t4->prev = t3->prev;
                        t4->next = t3;
                        if (t3->prev!=NULL) {//t3!=head
                            t3->prev->next = t4;
                        }
                        t3->prev = t4;
                        break;
                    }
                    else {//t3->power>power
                        //do nothing unless it is the end
                        if (t3->next==NULL) {
                            t4 = makeNode(data, power);
                            t4->prev = t3;
                            t3->next = t4;
                            break;
                        }
                    }
                }
            }
        }
    }
    return p3;

}
