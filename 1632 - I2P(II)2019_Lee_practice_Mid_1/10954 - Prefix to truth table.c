#include <stdio.h>
char expr[20];
int bin[5];//ABCD value
int pos;
int cal()
{
    if (pos>=strlen(expr)) return 0;

    char c = expr[pos++];

    if (c=='&') {
        return cal()&cal();
    }
    if (c=='|') {
        return cal()|cal();
    }
    if (c<='D'&&c>='A') {
        return bin[c-'A'];
    }
}
void truthtable(int n)
{
    int i;
    if (n==4) {
        for (i=0; i<4; i++) {
            printf("%d ", bin[i]);
        }
        printf("%d\n", cal());
        pos = 0;
    }
    else {
        bin[n] = 0;
        truthtable(n+1);
        bin[n] = 1;
        truthtable(n+1);
    }
}
int main()
{
    scanf("%s", expr);
    truthtable(0);
}
