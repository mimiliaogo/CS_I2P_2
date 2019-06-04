#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    vector <int> heap;
    string cmd;
    int val, max;
    while (cin>>cmd) {
        if (cmd=="PUSH") {
            cin>>val;
            if (heap.begin()==heap.end()||val>max)
                {
                    heap.push_back(val);
                    max = val;
                }
            else  {
               
                heap.push_back(val);
        	    sort(heap.begin(), heap.end());
            }
        
        }
        else if (cmd=="POP")
            heap.pop_back();
        else if (cmd=="TOP") 
            if (heap.begin()!=heap.end()) cout<<*(--(heap.end()))<<endl;
            else  cout<<"NULL"<<endl;
    }
}