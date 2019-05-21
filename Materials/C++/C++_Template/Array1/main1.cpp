#include <iostream>
#include <string>
#include "Array.h"

using namespace std;
using namespace I2P;

// test driver for Array class
int main()
{
    int i;
    try {
        Array<int, 3> A;

        for(i=0; i<3; i++)
            A.setElementAt(i, 2*(i+1));


    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
