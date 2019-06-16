#include <iostream>
#include <set>
using namespace std;
int main()
{
    set <int> par;
    set <int> chi;
    int p, c;
    int n;
    while(1) {
        int lvs = 0;
        cin>>n;
        if (n==0) break;
        else {
            while (n>0) {
                n--;
                cin>>p>>c;
                par.insert(p);
                chi.insert(c);
            }
            cin>>p;
        }
        for (auto c:chi) {
            if (par.find(c)==par.end()) lvs++;
        }
        cout<<lvs<<endl;
        par.clear();
        chi.clear();
    }
}
