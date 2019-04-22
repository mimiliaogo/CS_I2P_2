#include <iostream>
#include <string>
#include <stdexcept>
#include "9412_include.h"

using namespace std;

void List::InsertHead(const int data){

    if (head == nullptr) {
        head = new ListNode(data);
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        cnt = 1;
        pos = 1;
        middle = head;
    } else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        head->prev = nullptr;
        cnt++;
        pos++;
        if (pos > cnt/2){
            middle = middle->prev;
            pos--;
        }

    }

}

int List::RemoveHead(){
    ListNode* temp;
    int data = 0;

    if (head == nullptr){
        throw out_of_range("empty list");
    } else {
        data = head->data;
        temp = head;
        // consider 2 cases
        // case 1: 1 Node
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
            cnt = 0;
            pos = 0;
        }
        // case 2: more than 1 node
        else {
            head = head->next;
            head-> prev = nullptr;
            cnt--;
            pos--;
            if (pos < cnt/2){
                middle = middle->next;
                pos++;
            }
        }
        delete temp;
    }

    return data;
}

void List::InsertTail(const int data){
    if (tail == nullptr) {
        tail = new ListNode(data);
        tail->prev = nullptr;
        tail->next = nullptr;
        head = tail;
        middle = head;
        pos = 1;
        cnt = 1;
    } else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = nullptr;
        cnt++;
        if (pos < cnt/2){
            middle = middle->next;
            pos++;
        }
    }
}

int List::RemoveTail(){
    ListNode* temp;
    int data = 0;

    if (tail == nullptr){
        throw out_of_range("empty list");
    } else {
        data = tail->data;
        temp = tail;
        // consider 2 cases
        // case 1: 1 Node
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
            cnt = 0;
            pos = 0;
        }
        // case 2: others
        else {
            tail = tail->prev;
            tail->next = nullptr;
            cnt--;
            if (pos>cnt/2){
                middle = middle->prev;
                pos--;
            }
        }
        delete temp;
    }
    return data;
}

void List::Swap(){
    int i;

    // if cnt == 0 or cnt == 1, do nothing
    if (cnt>1) {
        // link the head and tail to form
        // a circular doubly linked list
        tail->next = head;
        head->prev = tail;

        // break the circular list from the middle node
        head = middle->next;

        // setup mid
        if (cnt%2 == 0)
            middle = tail;
        else
            middle = tail->prev;
        tail = head->prev;
        head->prev = nullptr;
        tail->next = nullptr;
    }
}


