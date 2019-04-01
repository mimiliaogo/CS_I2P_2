#include <stdio.h>
int main()
{
    int a[5];
    int i;
    for (i=0; i<5; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, 5);
    for (i=0; i<5; i++) {
        printf("%d ", a[i]);
    }

}
void swap(int* a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int a[], int len)
{
    int i;
    if (len==1) return;
    sort(a, len-1);//Sort the first n-1 numbers
    for (i=len-1; i>0 && a[i-1]>a[i]; i--) {//Insert the last element to the correct position
        swap(&a[i-1], &a[i]);
    }
}
