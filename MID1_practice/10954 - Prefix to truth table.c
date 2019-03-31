#include <stdio.h>
int num[10];//value of ABCD
char expr[40];
int pos;
int cal()
{
    char c;
    if (pos<strlen(expr)) {
        c = expr[pos++];
        if (c=='&') {
            return cal()&cal();
        }
        else if (c=='|') {
            return cal()|cal();
        }
        else if (c=='A') {
            return num[0];
        }
        else if (c=='B') {
            return num[1];
        }
        else if (c=='C') {
            return num[2];
        }
        else if (c=='D') {
            return num[3];
        }
    }

}
int main()
{
    scanf("%s", expr);
    truthtable(0);
}
void truthtable(int n)
{
    int i;
    if (n==4) {
        num[4] = cal();
        for (i=0; i<4; i++) printf("%d ", num[i]);
        printf("%d\n", num[4]);
        pos = 0;
    }
    else {
       num[n] = 0;
       truthtable(n+1);
       num[n] = 1;
       truthtable(n+1);
    }

}
