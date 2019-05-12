#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
class ListNode
{
    friend class OWList; //make OWList a friend
    friend class TWList; //make TWList a friend

public:
    ListNode( const int &info ) //constructor
    : data( info ), nextPtr( NULL )
    {
    } //end ListNode constructor

private:
    int data; //data
    ListNode *nextPtr; // next node in list
}; //end class ListNode


class OWList
{
public:
    //default constructor
    OWList();
    //destructor
    ~OWList();
    //insert node at front of list
    void insertAtFront( const int &value );
    //remove node from front of list
    void removeFromFront();
    //is List empty?
    bool isEmpty() const;
    //display contents of List
    void print() const;

protected:
    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;  //pointer to last node

}; // end class List

class TWList:public OWList
{
public:
    //default constructor
    TWList()
    :OWList()
    {
        /*It will still work correctly if you omit the constructor call of the base
          class in the above member initializer list. The compiler will invoke this
          default constructor of OWList implicitly.*/
    }
    //destructor
    ~TWList()
    {
        /*You don't need to delete the list again because the compiler
          will invoke the destructor of the base class OWList to do this.*/
    }
    //insert node at back of list
    void insertAtBack( const int &value );
    //delete node from back of list
    void removeFromBack();

};
#endif
