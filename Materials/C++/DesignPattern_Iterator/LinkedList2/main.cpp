#include <iostream>
#include "LinkedList.h"

using namespace std;
using namespace I2P2017;

int main()
{
    try {
        int i;
        LinkedList L1;

        for (i=0; i<5; i++)
            L1.pushBack(2*i);

        LinkedList::LLIterator it;
        for (it = L1.begin(); it != L1.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;

    } catch (const char* s) {
        cout << s;
    }

    return 0;
}
