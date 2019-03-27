#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;


void printInfix(Node *root){
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void constructTree(Node** head){
    char c;

    while((c=getchar())==' ');
    if (c=='\n')
        return;

    // your code
}


int main(void)
{
    int n;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        getchar();
        Node *root=NULL;
        constructTree(&root);// you have to implement this function
        printInfix(root);//output function
        printf("\n");
        freeTree(root);
        n--;
    }
    return 0;
}
