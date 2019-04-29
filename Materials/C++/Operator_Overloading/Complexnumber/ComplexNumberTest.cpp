#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main(){

    complex x, y;

    cout << "Enter a complex number (a+bi) : " << endl;
    cin >> x;

    cout << "Enter a complex number (a+bi) : " << endl;
    cin >> y;
    cout << x << " + " << y << " = " << x+y << endl;
    cout << x << " * " << y << " = " << x*y << endl;

    cout << "The negative of " << x << " is " << -x << endl;
    cout << "The conjugate of " << x << " is " << ~x << endl;

    cout << "++"<< x << " is ";
    cout << ++x << endl;
    cout << x << "++ is ";
    cout << x++ << endl;
    cout << "And after that, it becomes "<< x << endl;

    return 0;
}
