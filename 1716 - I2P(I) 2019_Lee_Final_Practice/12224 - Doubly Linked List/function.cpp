#include "function.h"
#include <iostream>
using namespace std;
void List::InsertHead(int data)
 {
     if(head==nullptr) {
        head = new ListNode(data);
        tail = middle = head;
        cnt = 1;
        pos = 1;
     } else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        cnt++;
        pos++;
        if (pos>cnt/2+1) {
            pos--;
            middle = middle->prev;
        }
     }
 }
int  List::RemoveHead()
{
    if (head==nullptr) throw out_of_range("empty list");
    else {
        int data = head->data;
        if (head->next==nullptr) {
            delete head;
            head=tail=middle=nullptr;
            cnt=pos=0;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            cnt--;
            pos--;
            if (pos<cnt/2+1) {
                pos++;
                middle = middle->next;
            }
        }
        return data;
    }
}
void List::InsertTail(int data)
{
    if(head==nullptr) {
        head = new ListNode(data);
        tail = middle = head;
        cnt = 1;
        pos = 1;
     } else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail = tail->next;
        cnt++;
        if (pos<cnt/2+1) {
            pos++;
            middle = middle->next;
        }
     }
}
int List::RemoveTail()
{
    if (head==nullptr) throw out_of_range("empty list");
    int data = tail->data;
    if (head->next==nullptr) {
        delete head;
        head=tail=middle=nullptr;
        cnt=0;
        pos=0;
    } else {
        tail = tail->prev;
        delete tail->next;
        tail->next= nullptr;
        cnt--;

        if (pos>cnt/2+1) {
            pos--;
            middle = middle->prev;
        }
    }
    return data;
}
void List::Swap()
{
    ListNode* tmp;
    if (cnt>1) {
        tail->next = head;
        head->prev = tail;
        if (cnt%2==0) tmp = head;
        else tmp = tail;
        head = middle;
        tail = middle->prev;
        middle = tmp;
    }
}

