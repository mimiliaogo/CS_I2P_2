#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Josephus(int n)
{
    if (n==1) return 1;
    else if (n%2 == 0)
        return 2*Josephus(n/2)-1;
    else return 2*Josephus(n/2)+1;
}

int main(int argc, char* argv[])
{
    int n, m;
    clock_t start_time, end_time;

    if (argc!=2){
        printf("Usage: alg n");
        printf("       m equals to 2");
        return 1;
    }

    n = atoi(argv[1]);
    m = 2;

    start_time = clock(); /* mircosecond */
    printf("%d\n",Josephus(n));
    end_time = clock();

    printf("%d 2 %f\n", n, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
