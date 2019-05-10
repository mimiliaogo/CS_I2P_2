#include <iostream>
#include <cstring>
#include "function.h"
using namespace std;
//calculate 2's power
int pow(int n)
{
    if (n==0) return 1;
    else return pow(n-1)*2;
}

Array_BST::Array_BST()
{
    memset(array, 0, sizeof(array));
}
void Array_BST::insert(const int& n)
{
    if (array[1]==0) {
        array[1] = n;
        Height = 1;
    } else {
        int i=1;
        while (array[i]!=0) {
            if (n<array[i]) i = 2*i;
            else if (n>array[i]) i = 2*i + 1;
			else return;//handle with '=='
        }
        array[i] = n;
        if (i>=pow(Height)) Height++;
    }
}
bool Array_BST::search(const int &n) const
{
    if (array[1]==0) return false;
    else {
        int i=1;
        while (array[i]!=n) {
            if (i>=pow(Height)) return false;
            if (n<array[i]) i = 2*i;
            else if (n>array[i]) i = 2*i + 1;
        }
        return true;
    }
}
List_BST::List_BST()
{
    root=nullptr;
}

ListNode* List_BST::createLeaf(int key) const
{
    return new ListNode(key);
}
void List_BST::deleteTree(ListNode *root)
{
    if (root==nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete [] root;
}
void List_BST::insert(const int &n)
{
    int h=1;
    ListNode* tmp = root, *newNode=nullptr;
    if (root==nullptr) {
        root = createLeaf(n);
        Height = 1;
    } else {
        while (tmp!=nullptr) {
            newNode = tmp;
            if (n<tmp->key) tmp = tmp->left;
            else if (n>tmp->key) tmp = tmp->right;
			else return;
            h++;
        }
        if (n<newNode->key) newNode->left = createLeaf(n);
        else newNode->right = createLeaf(n);
        if (h>Height) Height= h;
    }

}
bool List_BST::search(const int &n) const
{
    ListNode* tmp = root;
    while (tmp!=nullptr) {
        if (n<tmp->key) {
            tmp = tmp->left;
        } else if (n>tmp->key) {
            tmp = tmp->right;
        } else {
            return true;
        }
    }
    return false;
}
