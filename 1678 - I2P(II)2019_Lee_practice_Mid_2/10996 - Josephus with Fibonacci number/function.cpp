#include <iostream>
#include <cstring>
#include "function.h"
using namespace std;
void Josephus::generatecircularlinkedList(const int &n)
{
    if (n>=1) {
        head = new Node(1);
        Node* tmp = head;
        for (int i=2; i<=n; i++) {
            tmp->next = new Node(i);
            tmp = tmp->next;
        }
        tmp->next = head;
    }
}
void Josephus::generateFib(const int& n)
{
    if (n<=1) {
        sequence[0] = 1;
        sequence[1] = 1;
    } else {
        generateFib(n-1);
        sequence[n] = sequence[n-1] + sequence[n-2];
    }
}
Josephus::Josephus()
{
    head=nullptr;
    memset(sequence, 0, sizeof(sequence));
    noOfPeople = 0;
}
Josephus::Josephus(const int &n)
{
    generatecircularlinkedList(n);
    generateFib(n);
    noOfPeople = n;
}
Josephus::~Josephus()
{
    delete head;
}
int Josephus::kill()
{
    //stop at the node previous from kill_node
    //after killing, toward sequence-1 steps
    Node *tmp, *killnode;
    int cnt=0, step;
    for (tmp=head; tmp->next!=head; tmp = tmp->next);
    while (tmp->next!=tmp) {
        step = (sequence[cnt]-1)%noOfPeople;
        for (; step>0; step--) tmp = tmp->next;
        killnode = tmp->next;
        tmp->next = killnode->next;
        delete killnode;
        noOfPeople--;
        cnt++;
    }
    head = tmp;
    return head->number;
}
