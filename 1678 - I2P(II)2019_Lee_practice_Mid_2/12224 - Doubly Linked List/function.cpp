#include <iostream>
#include "function.h"
using namespace std;
void List::InsertHead(int data)
{
    if (head==nullptr) {
        head = new ListNode(data);
        middle = head;
        tail = head;
        cnt = 1;
        pos = 1;
    } else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        cnt++;
        pos++;
        if (pos>cnt/2+1) {
            middle = middle->prev;
            pos--;
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
            head = middle = tail = nullptr;
            pos = cnt = 0;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            cnt--;
            pos--;
            if (pos<cnt/2+1) {
                middle = middle->next;
                pos++;
            }
        }
        return data;
    }
}
void List::InsertTail(int data)
{
    if (head==nullptr) {
        head = new ListNode(data);
        middle = head;
        tail = head;
        cnt = 1;
        pos = 1;
    } else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail= tail->next;
        cnt++;
        if (pos<cnt/2+1) {
            middle = middle->next;
            pos++;
        }
    }

}
int  List::RemoveTail()
{
    if (head==nullptr) throw out_of_range("empty list");
    else {
        int data = tail->data;
        if (head->next==nullptr) {
            delete head;
            head = middle = tail = nullptr;
            pos = cnt = 0;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next= nullptr;
            cnt--;
            if (pos>cnt/2+1) {
                middle = middle->prev;
                pos--;
            }
        }
        return data;
    }
}
void List::Swap()
{
    if (cnt>1) {
        ListNode* curmid = middle;
        tail->next = head;
        head->prev = tail;
        if (cnt%2) middle = tail;
        else middle = head;
        head = curmid;
        tail = curmid->prev;
        head->prev = nullptr;
        tail->next = nullptr;
    }

}
