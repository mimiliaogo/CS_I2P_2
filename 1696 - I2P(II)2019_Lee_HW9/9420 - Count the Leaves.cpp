#include <iostream>
#include <set>
using namespace std;
int main()
{
    set <int> pr;
    set <int> cd;
    int lfcnt=0, num;
    int par, cld;
    while (1) {
        cin>>num;
        if (num==0) break;
        while (num>0) {
            num--;
            cin>>par>>cld;
            pr.insert(par);
            cd.insert(cld);
        }
        cin>>par;//root
        pr.insert(par);
        for (auto s:cd) {
            if (pr.find(s)==pr.end()) lfcnt++;
        }
        cout<<lfcnt<<endl;
        lfcnt = 0;
        pr.clear();
        cd.clear();
    }
}
