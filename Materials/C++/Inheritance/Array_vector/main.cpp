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
            testSetSize(*A[i]);

        /*
        Vector A(3);

        for(i=0; i<3; i++)
            A.setElementAt(i, 2*(i+1));

        A.setSize(5);
        for(i=3; i<5; i++)
            A.setElementAt(i, i*i);

        A.setSize(10);
        for(i=5; i<10; i++)
            A.setElementAt(i, i);

        A.print();
*/
    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
