#include <iostream>
#include <string>
#include "Array1.h"

using namespace std;
using namespace I2P2017;

// test driver for Array and vector class
int main()
{

    try {
        ContinuousList *CL[3];
        CL[0] = new Array(2);
        CL[1] = new Vector(2);
        CL[2] = new Array(3);
 //       CL[2] = new ContinuousList(2);


        for (int i=0; i< 3; i++)
            delete CL[i];
    } catch (const char *s) {
        cout << s << endl;
        cout <<"error message"<< endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

}
