#include <stdio.h>
int main()
{
    int a[5];
    int i;
    for (i=0; i<5; i++) {
        scanf("%d ", &a[i]);
    }
    bubble_sort(a, 5);
    for (i=0; i<5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    insertion_sort(a, 5);
    for (i=0; i<5; i++) {
        printf("%d ", a[i]);
    }
}
void swap(int*a, int*b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int a[], int len)
{
    int i, size;
    for (size=len; size>0; size--) {
        for (i=1; i<size; i++) {
            if (a[i-1]>a[i]) swap(&a[i-1], &a[i]);
        }
    }
}

void insertion_sort(int a[], int len)
{
    int i, size;
    for (size=2; size<=len; size++) {
        for (i=size-1; i>0 && a[i-1]>a[i]; i--) {
            swap(&a[i-1], &a[i]);
        }
    }
}
