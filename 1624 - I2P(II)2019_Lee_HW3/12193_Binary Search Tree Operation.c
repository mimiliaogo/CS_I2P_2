#include <stdio.h>
#include <string.h>
typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
}Node;

Node* newNode(int data)
{
    Node* np = (Node*) malloc(sizeof(Node));
    np->data = data;
    np->left = NULL;
    np->right = NULL;
    return np;
}
Node* insertNode(Node* root, int data)
{
    if (root==NULL) root = newNode(data);
    else {
        if (data<root->data) {
            root->left = insertNode(root->left, data);
        }
        else if(data>root->data) {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}
int NumofNode(Node* root, int level)
{
    if (root==NULL) return 0;
    if (level==1) return 1;
    else if (level>1){
        return NumofNode(root->left, level-1) + NumofNode(root->right, level-1);
    }
}
float AverLevel(Node* root, int level)
{
    return (float)(SumLevel(root, level)/(float)NumofNode(root, level));
}
//when the level arrive at the top , the root is the level place
int SumLevel (Node* root, int level)
{
    if (root==NULL) return 0;
    if (level==1) return root->data;
    else {
        return SumLevel(root->left, level-1) + SumLevel(root->right, level-1);
    }
}
void PInorder(Node* root)
{

    if (root!=NULL) {
        PInorder(root->left);
        printf("%d ", root->data);
        PInorder(root->right);
    }
}
int GetMax(Node* root)
{
    //find the max height of the left and right tree
    //then find the max of them, add 1
    int lmax, rmax;
    int treemax;
    if (root==NULL) return 0;
    lmax = GetMax(root->left);
    rmax = GetMax(root->right);
    if (lmax>rmax) treemax = lmax;
    else treemax = rmax;
    return treemax+1;
}
int main()
{
    int N, data;
    int cmdn;
    char cmd[20];
    int lev;
    Node* root = NULL;
    scanf("%d", &N);
    while (N>0) {
        N--;
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    scanf("%d", &cmdn);
    while (cmdn>0) {
        cmdn--;
        scanf("%s", cmd);

        if (strncmp(cmd, "P", 2)==0) {
            if (root==NULL) printf("NULL");
            else PInorder(root);
            printf("\n");
        }
        else if (strncmp(cmd, "A", 1)==0) {
            scanf("%d", &lev);
            if (lev>GetMax(root)||lev==0) printf("0\n");
            else printf("%.3f\n", AverLevel(root, lev));
        }
        else if (strncmp(cmd, "G", 1)==0) {
            printf("%d\n", GetMax(root));
        }
        else {
            scanf("%d", &lev);
            if (lev>GetMax(root)||lev==0) printf("0\n");
            else printf("%d\n", SumLevel(root, lev));
        }
    }
}
//9
//24 1 3 5 7 30 26 25 27
