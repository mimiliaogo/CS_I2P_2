#include <stdio.h>

#include <stdlib.h>

#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){

        /*YOUR CODE HERE*/
    if (inorder_start > inorder_end) {
        return NULL;
    }
    int cnt = 0;
    Node* root = (Node*) malloc (sizeof(Node));
    if (inorder_start==inorder_end) {
        root->data = preorder[0];
        root->left = NULL;
        root->right = NULL;
    }

    else {
        while (*(inorder+inorder_start+cnt)!=preorder[0]) cnt++;
        root->data = preorder[0];
        root->left = buildTree(inorder, preorder + 1, inorder_start, inorder_start+cnt-1);
        root->right = buildTree(inorder, preorder+cnt+1, inorder_start+cnt+1, inorder_end);
    }
    return root;

}

void showPostorder(Node* root){
      /*YOUR CODE HERE*/
    if (root!=NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->data);
    }
}
