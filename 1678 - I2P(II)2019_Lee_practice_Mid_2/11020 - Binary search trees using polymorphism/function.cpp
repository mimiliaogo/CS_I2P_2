#include <iostream>
#include <cstring>
#include <math.h>
#include"function.h"
using namespace std;
Array_BST::Array_BST()
{
    memset(array, 0, sizeof(array));
}

void Array_BST::insert(const int &n)
{ //root node is stored at index 1.
    int i=1;
    while (array[i]!=0) {
        if (n<array[i]) i = 2*i;
        else if (n>array[i]) i = 2*i + 1;
        else return;
    }
    array[i] = n;
    if (i>=pow(2, Height)) Height++;
}
bool Array_BST::search(const int &key) const
{
    int i=1;
    while (i<pow(2, Height)) {
        if (key<array[i]) i = 2*i;
        else if (key>array[i]) i = 2*i + 1;
        else return true;
    }
    return false;
}
ListNode* List_BST::createLeaf(int key) const
{
    return new ListNode(key);
}
void List_BST::deleteTree(ListNode *root)
{
    if (root!=nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
List_BST::List_BST()
{
    root=nullptr;
}
void List_BST::insert(const int &n)
{
    if (root==nullptr) {
        root = createLeaf(n);
        Height = 1;
    } else {
        int h=1;
        ListNode* tmp = root, *cur;
        while (tmp!=nullptr) {
            cur = tmp;
            if (n<tmp->key) tmp = tmp->left;
            else if (n>tmp->key) tmp = tmp->right;
            else return;
            h++;
        }
        if (n<cur->key) cur->left = createLeaf(n);
        else cur->right = createLeaf(n);
        if (h>Height) Height = h;
    }
}
bool List_BST::search(const int& key) const
{
    ListNode* tmp = root;
    while (tmp!=nullptr) {
        if (key<tmp->key) tmp = tmp->left;
        else if (key>tmp->key) tmp = tmp->right;
        else return true;
    }
    return false;
}
