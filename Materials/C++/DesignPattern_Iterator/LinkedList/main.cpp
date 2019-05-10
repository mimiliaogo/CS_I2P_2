#include <iostream>
#include "LinkedList.h"

using namespace std;
using namespace I2P2017;

int main()
{
    try {
        int i;
        LinkedList L1;

        for (i=0;i<5;i++)
            L1.pushBack(2*i);

        LLIterator *iter = L1.createIterator();
        for (iter->first(); !iter->isDone(); iter->next()){
            cout << iter->currentItem() << " ";
        }
        cout << endl;
        cout << iter->currentItem() << endl;

    } catch (const char* s) {
        cout << s;
    }

    return 0;
}
