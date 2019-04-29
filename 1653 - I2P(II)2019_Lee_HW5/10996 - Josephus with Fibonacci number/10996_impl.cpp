/*
constructor
destructor
int kill();
void generatecircularlinkedList(const int &);
void generateFib(const int &);
*/
#include <iostream>
#include "10996_include.h"
using namespace std;
Josephus::Josephus()//default constructor
{
    noOfPeople = 0;
    for (int i=0; i<50; i++) {
        sequence[i] = 0;
    }
    head = nullptr;
}
Josephus::Josephus(const int &n)
{
    noOfPeople = n;
    for (int i=0; i<50; i++) {
        sequence[i] = 0;
    }
    head = nullptr;
}
Josephus::~Josephus()
{
    delete head;
    head = nullptr;
}
int Josephus::kill() {
    if (noOfPeople<=0) return 0;
    generatecircularlinkedList(noOfPeople);
    generateFib(noOfPeople);

    Node* tmp;
    int cnt=0, i=0;

    for (tmp=head; tmp->next!=head; tmp = tmp->next);//the tail
    while (head->next!=head) {
        sequence[i]--;//since I let the start position move back
        if (sequence[i]>=noOfPeople) sequence[i] = (sequence[i])%noOfPeople;
        for (cnt=0; cnt<sequence[i]; cnt++) {
            tmp = head;
            head = head->next;
        }
        tmp->next = head->next;
        delete head;
        noOfPeople--;
        head = tmp->next;
        i++;
    }

    return head->number;
}
void Josephus::generatecircularlinkedList(const int & n) // generate circular linked-list
{
    int id;
    Node* prev=nullptr;
    head = new Node(1);
    prev = head;
    for (id=2; id<=n; id++) {
        prev->next = new Node(id);
        prev = prev->next;
    }
    prev->next = head;
}
void Josephus::generateFib(const int & n)
{
    if (n<2) {
        sequence[0] = 1;
        sequence[1] = 1;
    }
    else {
        generateFib(n-1);
        sequence[n] = sequence[n-1] + sequence[n-2];
    }
}
