#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//using priority_queue
int main()
{
    priority_queue <int> heap;
    string cmd;
    int val;
    while (cin>>cmd) {
        if (cmd=="PUSH") {
            cin>>val;
            heap.push(val);
        }
        else if (cmd=="POP")
            heap.pop();
        else if (cmd=="TOP") 
            if (!heap.empty()) cout<<heap.top()<<endl;
            else  cout<<"NULL"<<endl;
    }
}