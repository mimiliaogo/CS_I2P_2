#include <iostream>
#include "function.h"
using namespace std;
Str::Str(char* str)
{
    head = new Char(str[0]);
    int i=1;
    Char* tmp = head;
    while (str[i]!='\0') {
        tmp->next = new Char(str[i]);
        tmp = tmp->next;
        i++;
    }
    tail = tmp;
    tail->next = nullptr;
}
Str::Str(const Str &str)
{

    head = new Char(str.head->text);
    Char* ttmp = head;
    Char* tmp = str.head;
    while (tmp!=str.tail) {
        ttmp->next = new Char(tmp->next->text);
        ttmp = ttmp->next;
        tmp = tmp->next;
    }
    tail = ttmp;
    tail->next = nullptr;
}
bool Str::operator==(const Str & str) const
{
    Char* ttmp=head;
    Char* tmp = str.head;
    while (tmp!=nullptr) {
        if (ttmp->text!=tmp->text) return false;
        else {
            tmp = tmp->next;
            ttmp = ttmp->next;
        }
    }
    if(ttmp!=nullptr) return false;
    else return true;
}
