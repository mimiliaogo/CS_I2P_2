/*
Various way to show bubble_sort
included functions with "findmax"
"sort" of looping and recursion
*/
#include <stdio.h>
int main()
{
    int a[5];
    int i;
    for (i=0; i<5; i++) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, 5);
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
void FindMax(int a[], int len)//Looping ver.//Let a[i] always be the maximum of a[0..i].
{
    int i;
    for (i=1; i<len; i++) {
        if (a[i-1]>a[i]) swap(&a[len-1], &a[len-2]);
    }
}
void findmax(int a[], int len)//Recursion ver.
{
    if (len==1) return;
    findmax(a, len-1);
    if (a[len-1]<a[len-2]) swap(&a[len-1], &a[len-2]);
}
void Sort(int a[], int len)// without findmax
{
    int maxval, maxidx, i;
    if (len==1) return;
    maxval = a[0];
    maxidx = 0;
    for (i=1; i<len; i++) {
        if (maxval<a[i]) {
            maxval = a[i];
            maxidx = i;
        }
    }
    a[maxidx] = a[len-1];
    a[len-1] = maxval;
    Sort(a, len-1);
}
void sort(int a[], int len)
{
    if (len==1) return;
    FindMax(a, len);
    sort(a, len-1);
}

void bubble_sort(int a[], int len) {
    int size, i;
    for (size=len; size>0; size--) {
        for (i=1; i<size; i++) {
            if (a[i]<a[i-1]) swap(&a[i], &a[i-1]);
        }
    }
}



