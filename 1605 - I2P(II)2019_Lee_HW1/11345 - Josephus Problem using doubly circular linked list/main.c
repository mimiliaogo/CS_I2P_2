#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
//        show();
        printf("%d\n", solveJosephus(m));
    }

    return 0;
}

