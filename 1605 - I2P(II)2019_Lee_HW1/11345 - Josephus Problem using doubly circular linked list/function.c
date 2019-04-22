#include <stdio.h>
#include <stdlib.h>
#include "function.h"

man* createList(int n){

    int i;
    man* curr;
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr->next->prev = curr;
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    head->prev = curr;

    return head;
}


void deleteNode_after(man *cp)
{
    man* dp = cp->next;
    cp->next = dp->next;
    dp->next->prev = cp;

    free(dp);

}
int solveJosephus(int step){
    int cnt=1;
    man* cur = head;
    while (cur->next!=cur) {
		cnt = 1;
        while (cnt<step-1) {
            cnt++;
            cur = cur->next;
        }
        deleteNode_after(cur);
        if (cur->next==cur) break;
        cnt = 1;
        while (cnt<step-1) {
            cnt++;
            cur = cur->prev;
        }
        deleteNode_after(cur->prev->prev);
    }
    return cur->id;
}

