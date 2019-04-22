#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct man {
    int id;
    int next;
} man;


int main(int argc, char* argv[])
{
    int n, m, i, j;
    man *people;
    int current, remain, tmp;
    clock_t start_time, end_time;

    if (argc<3){
        printf("Usage: alg n m");
        return 1;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    start_time = clock(); /* mircosecond */

    /* using circular linked list*/
    people = (man*)malloc(n*sizeof(man));
    for(i=0; i<n; i++){
        people[i].id = i+1;
        people[i].next = i+1;
    }
    people[n-1].next = 0;
    current = 0;
    for(j=1;j<n;j++){
        for(i=1;i<m;i++){
            tmp = current;
            current = people[current].next;
        }
        people[tmp].next = people[current].next;
        current = people[current].next;
        remain --;
    }

    printf("%d\n",people[current].id);

    free(people);
    end_time = clock();

    printf("%d %d %f\n", n, m, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
