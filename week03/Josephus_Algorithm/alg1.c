#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int n, m, i, j;
    int *people;
    int current, remain;
    clock_t start_time, end_time;

    if (argc<3){
        printf("Usage: alg n m");
        return 1;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    start_time = clock(); /* mircosecond */
    /* using array*/
    people = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) people[i] = i+1;
    remain = n;
    current = 0;

    while(remain>1){
        current = current + m-1;
        while (current>remain-1) current = current - remain;
        remain --;

        /* remove the killed node*/
        for (i = current; i< remain; i++)
            people[i] = people[i+1];
    }

    printf("%d\n",people[0]);
    free(people);

    end_time = clock();

    printf("%d %d %f\n", n, m, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
