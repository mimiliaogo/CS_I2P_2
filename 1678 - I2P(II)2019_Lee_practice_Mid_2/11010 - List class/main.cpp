#include <iostream>
#include <string>
#include "function.h"
using namespace std;
int main()
{
    TWList integerList;
    int command;
    int value; // store node value

    while (cin >> command)
    {
        switch(command)
        {
        case 1: // insert at beginning
            cin >> value;
            integerList.insertAtFront(value);
            break;
        case 2: // insert at end
            cin >> value;
            integerList.insertAtBack(value);
            break;
        case 3: // remove from beginning
            integerList.removeFromFront();
            break;
        case 4: // remove from end
            integerList.removeFromBack();
            break;
        }
    }
    integerList.print();
    cout<<endl;
}
