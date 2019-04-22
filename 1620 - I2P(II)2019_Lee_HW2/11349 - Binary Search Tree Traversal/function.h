#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;
Node* newNode(int data)
{
    Node* np = (Node*) malloc(sizeof(Node));
    np->data = data;
    np->left = NULL;
    np->right = NULL;
    return np;
}
Node* insertNode(Node *root, int data)
{
    if (root==NULL) return newNode(data);
    else {
        if (data>root->data)
            root->right = insertNode(root->right, data);
        else if (data<root->data)
            root->left = insertNode(root->left, data);
    }
    return root;
}
void create_tree(Node **root, int n)
{
    int data;
    while (n>0) {
        n--;
        scanf("%d", &data);
        *root = insertNode(*root, data);
    }
}
void preorder(Node* root)
{
    if (root==NULL) return;
    else {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root)
{
    if (root==NULL) return;
    else {

        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
}
void print_tree(Node *root)
{
    printf("preorder:");
    preorder(root);
    printf("\n");
    printf("inorder:");
    inorder(root);
    printf("\n");
    printf("postorder:");
    postorder(root);
    printf("\n");

}
//void destroyTree(Node *root)
//{
//    if (root!=NULL) {
//        destroyTree(root->left);
//        destroyTree(root->right);
//        free(root);
//    }
//
//
//}

#endif
