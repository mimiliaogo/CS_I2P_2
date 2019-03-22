#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *left, *right;
} BTNode;


/* Print the binary tree in preorder.*/
void preorder(BTNode *root){

   if(root!=NULL) {
       printf("%d ", root->data);
	   preorder(root->left);
       preorder(root->right);
   }
}

/* find the maximum value in the tree. */
int findMax(BTNode *root){
    if (root==NULL) return 0;
    int max = root->data;
    int lval = findMax(root->left);
    int rval = findMax(root->right);
    if(lval > max) max = lval;
    if(rval > max) max = rval;
    return max;
}


/* generate a binary tree.
   maxLevel: maximum level of the tree.
   ratio: the 1/ratio to drop the node.
*/
BTNode *genBT(int maxLevel){
    if (maxLevel == 0) return NULL;

    BTNode *root = (BTNode*)malloc(sizeof(BTNode));
    root->data = rand()%100;
    root->left = genBT(maxLevel-1);
    root->right = genBT(maxLevel-1);

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
    BTNode *root = genBT(5);
    preorder(root);
    printf("\n The maximum is %d.\n", findMax(root));
    freeBinaryTree(root);

    return 0;
}

