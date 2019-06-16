#include <iostream>
#include "function.h"
using namespace std;
Node* makenode(long data, int power)
{
    Node* node;
    node = new Node;
    node->data = data;
    node->power = power;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}
Node* create()
{
    Node* head = nullptr;
    long data;
    int power;
    cin>>data>>power;
    head = makenode(data, power);
    if (power==0) return head;
    else {
        head->next = create();
        head->next->prev = head;
        return head;
    }

}
void printNode(Node* head)
{
    if (head==nullptr) return;
    else {
        if (head->data!=0L)
            cout<<' '<<head->data<<' '<<head->power;
        printNode(head->next);
    }
}
Node* multiple(Node* p1, Node* p2)
{
    Node* p3=nullptr;
    long data;
    int power;
    Node*np;
    Node* tmp3=nullptr,  *tmp3last;
    for (Node* tmp2=p2; tmp2!=nullptr; tmp2=tmp2->next) {
        for (Node* tmp1=p1; tmp1!=nullptr; tmp1=tmp1->next) {
            data = tmp2->data * tmp1->data;
            power = tmp2->power + tmp1->power;
            if (p3==nullptr) p3 = makenode(data, power);
            else {
                for (tmp3=p3; tmp3!=nullptr; tmp3=tmp3->next) {
                    tmp3last = tmp3;
                    if (power<tmp3->power) {}//doing nothing
                    else {//> or ==
                        if (power==tmp3->power) {
                            tmp3->data += data;
                        } else {
                            np = makenode(data, power);
                            tmp3->prev->next = np;
                            np->prev = tmp3->prev;
                            np->next = tmp3;
                            tmp3->prev = np;
                        }
                        break;
                    }
                }
                if (tmp3==nullptr) {
                    np = makenode(data, power);
                    tmp3last->next = np;
                    np->prev = tmp3last;
                    np->next = nullptr;
                }
            }
        }
    }
    return p3;
}
void destroy(Node *node)
{
    if (node!=nullptr) {
        destroy(node->next);
        delete node;
    }
}
