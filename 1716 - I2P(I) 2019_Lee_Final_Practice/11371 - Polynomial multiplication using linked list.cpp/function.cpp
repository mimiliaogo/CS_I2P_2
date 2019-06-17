#include <iostream>
#include "function.h"
using namespace std;
Node* newNode(int data, int power)
{
    Node* np = new Node;
    np->data = data;
    np->power = power;
    np->next = np->prev = nullptr;
    return np;
}
Node* create()
{
    int n;
    long data;
    int power;
    cin>>data>>power;
    Node* head = newNode(data, power);
    if (power!=0) {
        head->next = create();
        head->next->prev = head;
    }
    return head;
}
void printNode(Node* head)
{
    if (head) {
        if (head->data!=0) cout<<' '<<head->data<<' '<<head->power;
        printNode(head->next);
    }

}
Node* multiple(Node* p1, Node* p2)
{
    Node* p3=nullptr;
    Node* tmp4;
    for(Node*tmp2=p2; tmp2!=nullptr; tmp2=tmp2->next) {
        for (Node*tmp1=p1; tmp1!=nullptr; tmp1=tmp1->next) {
            long data = tmp2->data * tmp1->data;
            int power = tmp2->power+tmp1->power;
            if (p3==nullptr) p3 = newNode(data, power);
            else {
                Node*tmp3;
                for (tmp3=p3; tmp3!=nullptr; tmp3=tmp3->next) {
                    tmp4 = tmp3;
                    if (power==tmp3->power) {
                        tmp3->data +=data;
                        break;
                    } else if (power>tmp3->power){
                        Node* np = newNode(data, power);
                        np->next = tmp3;
                        np->prev = tmp3->prev;
                        tmp3->prev->next = np;
                        tmp3->prev = np;
                        break;
                    }
                }
                if (tmp3==nullptr) {
                    tmp4->next = newNode(data, power);
                    tmp4->next->prev = tmp4;
                }

            }
        }
    }
    return p3;
}
void destroy(Node *node)
{
    if (node) {
        destroy(node->next);
        delete node;
    }
}
