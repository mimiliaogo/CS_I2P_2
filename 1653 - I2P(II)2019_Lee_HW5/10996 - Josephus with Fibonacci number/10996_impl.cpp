#include <iostream>
#include <cstring>
#include "10996_include.h"
using namespace std;
Josephus::Josephus()//default constructor
{
    noOfPeople = 0;
    memset(sequence, 0, sizeof(sequence));
    head = nullptr;
}
Josephus::Josephus(const int &n)
{
    noOfPeople = n;
    generateFib(n);
    generatecircularlinkedList(n);
}
Josephus::~Josephus()
{
    delete head;
    head = nullptr;
}
int Josephus::kill() {
    Node* cur=head, *killnode=nullptr;
    int i=0, step;
    while (cur->next!=head) cur = cur->next;
    while (cur->next!=cur) {
        step = (sequence[i]-1)%noOfPeople;
        i++;
        for (;step>0; step--) cur = cur->next;

        killnode = cur->next;
        cur->next = killnode->next;
        delete killnode;
        noOfPeople--;
    }
    head = cur;
    return cur->number;

}
void Josephus::generatecircularlinkedList(const int & n) // generate circular linked-list
{
    int i=2;
    head = new Node(1);
    Node*cur = head;
    while (i<=n) {
        cur -> next = new Node(i);
        cur = cur->next;
        i++;
    }
    //cur == tail
    cur->next = head;

}
void Josephus::generateFib(const int & n)
{
    if (n<=1) {
        sequence[0] = 1;
        sequence[1] = 1;
    } else {
        generateFib(n-1);
        sequence[n] = sequence[n-1] + sequence[n-2];
    }
}
