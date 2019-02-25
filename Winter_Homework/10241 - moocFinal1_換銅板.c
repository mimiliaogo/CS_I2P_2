#include <stdio.h>
int values[10];
int numbers[10];
void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}
void money(int smallest, int nv, int amount)
{
    int i;
    if (smallest<nv) {
        if (amount==0) show(nv);
        else if (amount>0){
            //減少面額數
            money(smallest+1, nv, amount);
            //用最小的面額
            numbers[smallest]++;
            money(smallest, nv, amount-values[smallest]);
            numbers[smallest]--;
        }
    }
}
int main()
{
    int amount;
    int nv, i, j;
    scanf("%d", &nv);
    for(i=0; i<nv; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%d", &amount);
    money(0, nv, amount);
}
