#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

struct Cat {
    string name;
    int occup;
    int age;
};
bool cmp(const Cat &a, const Cat &b) {
        if (a.occup<b.occup) return true;
        else if (a.occup>b.occup) return false;
        else {
            if (a.age>b.age) {
                if (a.occup==5) return false;
                else return true;
            } else if (a.age<b.age) {
                if (a.occup==5) return true;
                else return false;
            }
            else {
                return a.name<b.name;
            }
        }

}
int main()
{
    int cnum, food;
    string temp;
///remember to initialize the vector before using []
    while ( cin>>cnum>>food) {
        vector<Cat> CatVec(cnum);

        for (int i=0; i<cnum; i++) {
            cin>>CatVec[i].name;
            cin>>temp;
            cin>>CatVec[i].age;


            switch (temp[0])
            {
                case 'e': CatVec[i].occup = 1;  break;
                case 'n': CatVec[i].occup = 2;  break;
                case 'k': CatVec[i].occup = 3;  break;
                case 'w': CatVec[i].occup = 4;  break;
                case 'a': CatVec[i].occup = 5;  break;
                case 'm': CatVec[i].occup = 6;  break;
                case 'd': CatVec[i].occup = 7;  break;
                case 'l': CatVec[i].occup = 8;  break;
                default: CatVec[i].occup = 100;
            }

        }
        sort(CatVec.begin(), CatVec.end(), cmp);
        if (food>cnum) food = cnum;
        for (int i=0; i<food; i++) {
            cout<<CatVec[i].name<<'\n';
        }
    }


}


