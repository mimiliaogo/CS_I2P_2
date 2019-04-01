#include <stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end);
void caculateLeafNodesSum(Node* root);
void freeTree(Node *root);
