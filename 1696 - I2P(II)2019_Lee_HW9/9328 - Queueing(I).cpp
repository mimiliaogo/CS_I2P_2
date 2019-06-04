#include <iostream>
#include <algorithm>
#include <queue>
/* pop() emplace() */
using namespace std;
int main()
{
    queue <string> q;
    string cmd;
    string name;
    while (cin>>cmd) {
        if (cmd=="Push") {
            cin>>name;
            q.push(name);
        } else if (cmd=="Pop") {
            if (!q.empty()) {
                q.pop();
            }
        } else if (cmd=="Front") {
            if (q.empty()) cout<<"empty"<<endl;
            else cout<<(q.front())<<endl;
        }
    }
}
