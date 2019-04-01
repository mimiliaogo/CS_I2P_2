#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct man {
    int id;
    struct man* next;
} man;


int main(int argc, char* argv[])
{
    int n, m, i, j;
    man *head, *curr, *tmp;
    int current, remain, count;
    clock_t start_time, end_time;

    if (argc<3){
        printf("Usage: alg n m");
        return 1;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    start_time = clock(); /* mircosecond */

    /* using circular linked list*/
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    curr = head;
    remain = n;
    while(remain>1){
        for(i=1;i<m;i++){
            tmp = curr;
            curr = curr->next;
        }
        tmp->next = curr->next;
        free(curr);
        curr = tmp->next;
        remain --;
    }

    printf("%d\n",curr->id);

    free(curr);
    end_time = clock();

    printf("%d %d %f\n", n, m, (float)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
