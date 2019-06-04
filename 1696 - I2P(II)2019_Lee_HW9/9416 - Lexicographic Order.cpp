#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <string> v;
    int cnt;
    string str;
    while (1) {
        cin>>cnt;
        if (cnt==0) break;
        else {
            while (cnt>0) {
                cnt--;
                cin>>str;
                v.push_back(str);
            }
            sort(v.begin(), v.end());
            for (auto s:v) cout<<s<<endl;
        }
        v.clear();
        cout<<endl;
    }
}
