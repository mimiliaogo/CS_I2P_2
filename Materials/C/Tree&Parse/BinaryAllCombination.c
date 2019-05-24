#include <stdio.h>
int bin[10];
int main()
{
//    allcom(4, 0);
    bitop(3);
}
void allcom(int bit, int n)//recursion
{
    int i;
    if (n==bit) {
        for (i=0; i<bit; i++) {
            printf("%d", bin[i]);
        }
        printf("\n");
    }
    else {
        bin[n] = 0;
        allcom(bit, n+1);
        bin[n] = 1;
        allcom(bit, n+1);
    }

}
void bitop(int bit)//bitwise
{
    int i, j;
    int lim = 1<<bit;
    for (i=0; i<lim; i++) {
        for (j=bit-1; j>=0; j--) {
            if (((1<<j)&i)>0) printf("%d", 1);
            else printf("%d", 0);
        }
        printf("\n");
    }
}
