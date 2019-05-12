#include <iostream>
#include "function.h"
using namespace std;
OWList::OWList()// initializes the two pointers firstPtr and lastPtr as NULL.
{
    firstPtr = nullptr;
    lastPtr  = nullptr;
}
OWList::~OWList()//deletes allocated dynamic memory space.
{
    if (firstPtr) {
        for (ListNode* tmp=firstPtr; tmp!=nullptr; tmp=tmp->nextPtr)
            delete tmp;
    }
}
void OWList::insertAtFront( const int &value )
{
    if (firstPtr==nullptr) {
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    } else {
        ListNode* np = new ListNode(value);
        np->nextPtr = firstPtr;
        firstPtr = np;
    }
}
void OWList::removeFromFront()
{
    if (firstPtr!=nullptr) {
        if (firstPtr->nextPtr==nullptr) {
            delete firstPtr;
            firstPtr = nullptr;
            lastPtr = nullptr;
        } else {
            ListNode* tmp = firstPtr;
            firstPtr = firstPtr->nextPtr;
            delete tmp;
        }
    }
}
bool OWList::isEmpty() const
{
    if (firstPtr==nullptr) return true;
    else return false;
}

void OWList::print() const
{
    for (ListNode* tmp=firstPtr; tmp!=lastPtr; tmp=tmp->nextPtr)
        cout<<tmp->data<<" ";
    if (lastPtr!=nullptr) cout<<lastPtr->data;
}
void TWList:: insertAtBack( const int &value )
{
    if (firstPtr==nullptr) {
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    } else {
        lastPtr->nextPtr = new ListNode(value);
        lastPtr = lastPtr->nextPtr;
    }
}
void TWList:: removeFromBack()
{
    if (firstPtr!=nullptr) {
        if (firstPtr->nextPtr==nullptr) {
            delete firstPtr;
            firstPtr=nullptr;
            lastPtr = nullptr;
        } else {
            ListNode* tmp;
            for (tmp=firstPtr; tmp->nextPtr!=lastPtr; tmp=tmp->nextPtr);
                ListNode* killnode = lastPtr;
                delete killnode;
                lastPtr = tmp;
                lastPtr->nextPtr = nullptr;
        }
    }
}
