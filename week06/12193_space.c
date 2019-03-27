#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node *left;
    struct _Node *right;
} Node;

Node* makeNode(int data){
    Node *p = (Node*) malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Node* root, int data){
    if (root->data > data){
    } else if (root->data < data){
    } // ignore the input if root->data == data
}

Node* buildBST(){
    int n, i, data;
    Node *root = NULL;

    scanf("%d", &n);
    if (n>0) {
        scanf("%d", &data);
        root = makeNode(data);

        for (i=1; i<n; i++){
            scanf("%d", &data);
            insertNode(root, data);
        }
    }
    return root;
}


void printInorder(Node *root){
    if(root!=NULL){
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int getMax(Node *root){
    int left, right;
    if (root==NULL)
        return 0;

    // your code
}

void getLevelInfo(Node* root, int level, int *count, int *sum){
    if (root == NULL)
        return;
    // your code
}

int main(void){
    int m, nlvl, i, lvl;
    Node* root=NULL;
    int *count=NULL, *sum=NULL;
    char cmd[10];

    root = buildBST();
    nlvl = getMax(root);
    if(nlvl>0){
        count = (int*) malloc(sizeof(int)*nlvl);
        sum = (int*) malloc(sizeof(int)*nlvl);
        for (i=0; i<nlvl; i++) {
            count[i] = 0;
            sum[i] = 0;
        }
    }
    getLevelInfo(root, 0, count, sum);

    scanf("%d", &m);
    for(i=0;i<m;i++){
        scanf("%s", cmd);
        if (strcmp(cmd, "P")==0) {
            if (root == NULL)
                printf("NULL\n");
            else{
                printInorder(root);
                printf("\n");
            }
        } else if (strcmp(cmd, "GetMax")==0) {
            printf("%d\n", nlvl);
        } else if (strcmp(cmd, "SumLevel")==0) {
            scanf("%d", &lvl);
            if (lvl<=0 || lvl > nlvl)
                printf("0\n");
            else
                printf("%d\n", sum[lvl-1]);
        } if (strcmp(cmd, "AverLevel")==0) {
            scanf("%d", &lvl);
            if (lvl<=0 || lvl > nlvl)
                printf("0\n");
            else
                printf("%.3f\n", ((float)sum[lvl-1])/count[lvl-1]);
        }
    }

    return 0;
}
