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
        Array A(5), B(5);

        for(i=0; i<5; i++) {
            A[i] = 2*(i+1);
            B[i]  = 3*i;
        }
        B = A;
        Array C = -A;
//        C = A.operator+(B);
        cout << A++ << endl;
        cout << A << endl;
        //cout << C << endl;

/*
        for(i=0; i<5; i++)
            cout<< C[i] << " ";
        cout << endl;
*/
/*
        cin >> A >> B;
        cout << A << endl;
        cout << B << endl;

        Array C = A + B;
        cout << C << endl;
*/
    } catch (const char* s) {
        cout << s << endl;
    }catch (exception& e) {
        cout << e.what() << endl;
    }
}
