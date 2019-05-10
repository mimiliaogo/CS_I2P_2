#include <iostream>
#include <string>
#include "Array.h"

using namespace std;
using namespace I2P2017;

void testSetSize(Array &A)
{
    try {
        A.setSize(4);
        A.print();
    } catch (const char *s){
        cout << s << endl;
    }

}

// test driver for Array and vector class
int main()
{
    int i;
    try {
        Vector A(3);
        A.setElementAt(0, 3);
        A.setSize(5);
        A.print();
        Array B(1);
        B.setElementAt(0, 2);
        B.print();
        Array* a[10];
        a[0] = new Array(3);
        a[0]->setElementAt(0, 22);
        a[0]->print();
    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

