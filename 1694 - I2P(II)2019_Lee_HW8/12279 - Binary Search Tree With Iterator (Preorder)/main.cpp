#include <iostream>
#include "function.h"

using namespace std;

int main()
{

    int G, N, tmp;
    
    BST bst;
    
    cin>>N>>G;
    
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        bst.push_back(tmp);
    }

    auto it = bst.begin();
    auto it2 = bst.begin();
    auto end = bst.end();
    while( it != end )
    {
        if( it2 != end ) it2++;
        if( it2 != end ) it2++;
        cout << *it + G << endl;
        it++;
    }
    
    return 0;
}

