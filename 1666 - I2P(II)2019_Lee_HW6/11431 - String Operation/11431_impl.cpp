//
// Created by user on 4/27/2019.
//
#include <iostream>
#include "11431.h"
using namespace std;
Str::Str(char* str)
{
    int i=1;
    head = new Char(str[0]);
    Char* temp=head;
    while (str[i]!='\0') {
        temp->next = new Char(str[i]);
        i++;
        temp = temp->next;

    }
    tail = temp;
    tail->next = nullptr;
}
//copy constructor
Str::Str(const Str &str)
{
    int i=1;
    head = new Char(str.head->text);
    Char* temp=head;
    Char* temp_str = str.head->next;
    while (temp_str!=nullptr) {
        temp->next = new Char(temp_str->text);
        temp_str = temp_str->next;
        temp = temp->next;
    }
    tail=temp;
    tail->next = nullptr;
}
bool Str::operator==(const Str & str) const
{
    Char* this_temp = head;
    Char* str_temp = str.head;
    while (this_temp!=nullptr && str_temp!=nullptr)
    {
        if (this_temp->text!=str_temp->text) return false;
        this_temp = this_temp->next;
        str_temp = str_temp->next;
    }
    if (this_temp!=nullptr || str_temp!=nullptr) return false;
    return true;
}
