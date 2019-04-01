#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum status {DEAD, ALIVE};
int main(int argc, char* argv[])
{
    int n, m, i, j, iter;
    int *people, *mark;
    int current, remain, count;
    clock_t start_time, end_time;

    if (argc<3){
        printf("Usage: alg n m");
        return 1;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    start_time = clock(); /* mircosecond */

    /* using array and mark*/
    people = (int*)malloc(n*sizeof(int));
    mark = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) {
        people[i] = i+1;
        mark[i] = ALIVE;
    }
    current = 0;
    remain = n;

    while(remain>1){
        for(count  = 0; count < m; ){
            if (mark[current] == ALIVE) count++;
            if (count <m) {
                current = current + 1;
                if (current >=n) current = 0;
            }
        }
        mark[current] = DEAD;
        remain --;
    }
    /*find the alive one.*/
    for(i=0;i<n;i++)
        if (mark[i]==ALIVE) break;
    printf("%d\n",people[i]);

    free(people);
    free(mark);
    end_time = clock();

    printf("%d %d %f\n", n, m, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
