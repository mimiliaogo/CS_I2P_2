#include <iostream>
#include <string>
#include "Array.h"

using namespace std;
using namespace I2P2019;

// test driver for Array class
int main()
{
    int i;
    try {
        Array A(10);

        for(i=0; i<10; i++)
            A.setElementAt(i, 2*(i+1));

        for(i=0; i<10; i++)
            cout<< A.getElementAt(i) << " ";
        cout << endl;

        A.getElementAt(11);

//        A.setArraySize(5);

//        Array B(-1);
    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
