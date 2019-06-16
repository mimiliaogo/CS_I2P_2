#include <iostream>
#include <stack>
using namespace std;
///using stack
int Calculate()
{
    stack<int> st;
    char c;
    int c1, c2;
    int ans;
    int num;
    while (1) {
        c = getchar();
      //  putchar(c);
        if (c=='0') break;
        if (c=='+'||c=='-'||c=='*'||c=='/') {
            c2 = st.top();
            st.pop();
            c1 = st.top();
            st.pop();
            switch(c) {
                case '+': ans = c1+c2; break;
                case '-': ans = c1-c2; break;
                case '*': ans = c1*c2; break;
                case '/': ans = c1/c2; break;
            }
            st.push(ans);
        } else if (c!='\n'&&c!=' '){
            ungetc(c, stdin);
            cin>>num;
            st.push(num);
        }
    }
    return st.top();
}
int main()
{

    cout<<Calculate()<<endl;
}
