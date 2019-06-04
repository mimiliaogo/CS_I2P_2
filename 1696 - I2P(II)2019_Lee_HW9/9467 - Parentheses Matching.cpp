#include <iostream>
#include <stack>
#include <map>
using namespace std;
//{S}, [S], (S) and <S>
map <char, char> match;
bool Ismatch(string s)
{
    stack <char> paren;
    if (s.empty()) return true;
    for (auto c: s) {
        if (c=='['||c=='('||c=='{'||c=='<')
            paren.push(c);
        else {
            if (paren.empty()||c!=match[paren.top()]) return false;
            else {
                paren.pop();
            }
        }
    }
    if (paren.empty())return true;
    else return false;
}
int main()
{
    int n;
    string str;
    match['('] = ')';
    match['{'] = '}';
    match['<'] = '>';
    match['['] = ']';
    cin>>n;
    getline(cin, str);//eating blank
    for (int i=1; i<=n; i++){
        getline(cin, str);
        cout<<"Case "<<i<<": ";
        if (Ismatch(str)) {
            cout<<"Yes"<<endl;
        } else cout<<"No"<<endl;
    }

}
