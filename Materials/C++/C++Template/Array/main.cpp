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
        Array<int> A(3);

        for(i=0; i<3; i++)
            A.setElementAt(i, 2*(i+1));

        for(i=0; i<3; i++)
            cout<< A.getElementAt(i)<< " ";
        cout << endl;

        Array<string> B(2);

        B.setElementAt(0, "First Element");
        B.setElementAt(1, "Second Element");
        cout<< B.getElementAt(0) << endl;
        cout<< B.getElementAt(1) << endl;

    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
