#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>       /* log */

int main(int argc, char* argv[])
{
    int n, m, k;
    double nd, lg;
    clock_t start_time, end_time;

    if (argc!=2){
        printf("Usage: alg n");
        printf("       m equals to 2");
        return 1;
    }

    n = atoi(argv[1]);
    m = 2;

    start_time = clock(); /* mircosecond */
    nd = (double)n;
    lg = log(nd)/log(2);
    k = n - (1<<((int)lg));
    printf("%d\n",2*k+1);
    end_time = clock();

    printf("%d 2 %f\n", n, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
