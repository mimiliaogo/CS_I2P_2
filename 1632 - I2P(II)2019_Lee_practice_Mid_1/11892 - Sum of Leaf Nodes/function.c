#include <stdio.h>
#include "function.h"
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{

    if (inorder_start>inorder_end) return NULL;
    Node* root = (Node*) malloc(sizeof(Node));
    if (inorder_start==inorder_end) {//only one data
        root->data = preorder[0];
        root->left = NULL;
        root->right = NULL;
    }
    else {
        int cnt = 0;
        //calculate the number of left subtree
        while (*(inorder+inorder_start+cnt)!=preorder[0]) cnt++;
        root->data = preorder[0];
        root->left = buildTree(inorder, preorder+1, inorder_start, inorder_start+cnt-1);
        root->right = buildTree(inorder, preorder+1+cnt, inorder_start+cnt+1, inorder_end);
    }
    return root;
}
int calleafsum(Node* root) {
    if (root==NULL) return 0;
    if (root->left==NULL&&root->right==NULL) return root->data;
    return calleafsum(root->left) + calleafsum(root->right);
}
void caculateLeafNodesSum(Node* root)
{
    printf("%d\n", calleafsum(root));

}
