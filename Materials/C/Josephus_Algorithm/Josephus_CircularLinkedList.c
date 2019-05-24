#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
    int id;
    struct _node* next;
} Node;
void insertNode(Node* cp) //insert the node after cp
{
    Node* np;
    np = (Node*) malloc(sizeof(Node));
    np->next = cp->next;
    cp->next = np;
}
void deleteNode(Node* cp)//delete the node after cp
{
    Node* dp;
    dp = cp->next;
    cp->next = dp->next;
    free(dp);

}
int main()
{
    Node* head;
    Node* cur, *tmp;
    int n, m, i;
    scanf("%d%d", &n, &m);

    head = (Node*) malloc(sizeof(Node));
    head->id = 1;
    head->next = head;

    cur = head;

    for (i=1; i<n; i++) {
        insertNode(cur);
        cur = cur->next;
        cur->id = i + 1;
    }

    cur = head;

//    for (i=0; i<n; i++) {
//        printf("%d ", cur->id);
//        cur = cur->next;
//    }


    while (cur->next!=cur) {
        for (i=1; i<m; i++){
            tmp = cur;
            cur = cur->next;
        }
        deleteNode(tmp);
        cur = tmp->next;
    }

    printf("%d", cur->id);




}
