#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} BTNode;


/* Print the binary tree in preorder.*/
void preorder(BTNode *root){

   if(root!=NULL) {
       printf("%d ", root->data);
	   preorder(root->left);
       preorder(root->right);
   }
}

/* generate a binary tree.
   maxLevel: maximum level of the tree.
   ratio: the 1/ratio to drop the node.
*/
BTNode *genBT(int maxLevel, int data){
    if (maxLevel == 0) return NULL;

    BTNode *root = (BTNode*)malloc(sizeof(BTNode));
    root->data = data;
    root->left = genBT(maxLevel-1, 2*data);
    root->right = genBT(maxLevel-1, 2*data+1);

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
    BTNode *root = genBT(5, 1);
    preorder(root);
    freeBinaryTree(root);

    return 0;
}
