#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 //#define ONLINE_JUDGE

/*
struct for product items
*/
typedef struct _Product {
    char name[51];
    float price;
    float review;
    int  num_reviews;
} Product;

int compare(const void *a, const void *b)
{
    Product *ia, *ib;
    ia = *(Product **)a;
    ib = *(Product **)b;
    /* your code here */
    if (compare_name(ia,ib)==0) {
        if (ia->review<ib->review) return 1;
        else if (ia->review>ib->review) return -1;
        else return (ia->price-ib->price);
    }
    else return compare_name(ia,ib);

}

int my_strcmp(char *s1, char *s2)
{
    /* your code here */
    int i=0;
    while (s1[i]!=' '&&s2[i]!=' ') { //到第一個空白
        if (s1[i]>s2[i]) return 1;
        else if (s1[i]<s2[i]) return -1;
        i++;
    }
    return 0;
}
int compare_name(const void *a, const void *b)
{
    /* your code here */
    Product *ia, *ib;
    ia = (Product*) a;
    ib = (Product*) b;

    return my_strcmp(ia->name, ib->name);
}

void show_product(Product *item)
{
    printf("%s, ", item->name);
    printf("$%.2f, ", item->price);
    printf("%.1f\n", item->review);
}

int main(void)
{
    Product **items;
    int i, j;
    int ndata, nqueries;
    Product **filtered;
    float lower, upper;
    int num;

#ifndef ONLINE_JUDGE
    freopen("10222_2_in.txt", "r", stdin);
//    freopen("out1.txt", "w", stdout);
#endif
    scanf("%d", &ndata);
    while (getchar() !='\n');

    items = (Product**) malloc(sizeof(Product*) * ndata);

    for (i=0; i<ndata; i++) {
        items[i] = (Product*) malloc(sizeof(Product));
        fgets(items[i]->name, 31, stdin);
        items[i]->name[strlen(items[i]->name)-1] = '\0';
        scanf("%f", &items[i]->price);
        scanf("%f", &items[i]->review);
        scanf("%d", &items[i]->num_reviews);
        while (getchar() !='\n');
    }

    scanf("%d", &nqueries);
    while (getchar() !='\n');

    qsort(items, ndata, sizeof(Product *), compare);

    filtered = (Product**) malloc(sizeof(Product*) * ndata);
    for (i=0; i<nqueries; i++) {
        scanf("%f%f", &lower, &upper);
        printf("%.2f<=price<=%.2f\n", lower, upper);

        /* your code here */
        int t;
        for (t=0; t<ndata; t++) {
            if (items[t]->price<=upper && items[t]->price>=lower) {
                show_product(items[t]);
            }
        }

    }

    for (i=0; i<ndata; i++) {
        free(items[i]);
    }
    free(items);
    free(filtered);
    return 0;
}
