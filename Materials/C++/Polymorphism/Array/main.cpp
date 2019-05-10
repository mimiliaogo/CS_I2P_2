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
        Array *A[3];
        A[0] = new Vector(1);
        A[1] = new Array(2);
        A[2] = new Vector(3);

        for (i=0;i<3;i++)
            delete A[i];
        //    testSetSize(*A[i]);
        //    A[i]->print();
    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

}
