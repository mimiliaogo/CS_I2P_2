#include <iostream>
#include <vector>
#include <algorithm>//for heap operation
#include <string>
#include <iostream>
using namespace std;
//using heap stl to solve

int main()
{
    vector <int> v;
    string cmd;
    int i;
    while (cin>>cmd) {
        if (cmd=="PUSH") {
            cin >> i;
            v.push_back(i);
            push_heap(v.begin(), v.end());
        } else if (cmd=="POP") {
            pop_heap(v.begin(), v.end());
            v.pop_back();
        } else if (cmd=="TOP") {
            if (v.begin()!=v.end())
                cout<<v.front()<<endl;
            else cout<<"Null"<<endl;
        }
    }
}