#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *left, *right;
} BTNode;


/* Print the binary tree in preorder.*/
void postorder(BTNode *root){

   if(root!=NULL) {
	   postorder(root->left);
       postorder(root->right);
       printf("%d ", root->data);
   }
}

/* generate a binary tree from pre-order and in-order list.
*/
BTNode *construct(int N, int pre[], int in[]){
    int cnt=0;
    if (N == 0) return NULL;

    while(cnt<N && in[cnt]!=pre[0])
        cnt++;

    if (cnt==N) return NULL;

    BTNode *root = (BTNode*)malloc(sizeof(BTNode));
    root->data = pre[0];
    root->left = construct(cnt, pre+1, in);
    root->right = construct(N-cnt-1, pre+cnt+1, in+cnt+1);

    /*
    // for debugging
    printf("root=%d, ", pre[0]);
    if (root->left!=NULL) printf("left=%d, ", root->left->data);
    else printf("left=NULL,");
    if (root->right!=NULL) printf("right=%d\n", root->right->data);
    else printf("right=NULL\n");
    */
    return root;
}


/* free the space of a binary tree. */
void freeBinaryTree(BTNode *root){
    if (root == NULL) return;

    freeBinaryTree(root->left);
    freeBinaryTree(root->right);

    free(root);
}


int main(){
    int i, N;
    int *pre, *in;

    scanf("%d", &N);
    pre = (int*)malloc(sizeof(int)*N);
    in  = (int*)malloc(sizeof(int)*N);

    // read in the pre-order list
    for(i=0; i<N; i++) {
        scanf("%d", &pre[i]);
    }

    // read in the in-order list
    for(i=0; i<N; i++) {
        scanf("%d", &in[i]);
    }

    BTNode *root = construct(N, pre, in);
    postorder(root);
    freeBinaryTree(root);

    return 0;
}

/* test case
9
2 7 3 6 8 11 5 9 4
3 7 8 6 11 2 5 4 9
*/
