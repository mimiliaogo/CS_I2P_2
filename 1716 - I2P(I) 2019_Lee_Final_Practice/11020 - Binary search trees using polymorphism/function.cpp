#include <iostream>
#include <cstring>
#include "function.h"
using namespace std;

Array_BST::Array_BST()
{
    memset(array, 0, sizeof(array));
}
void Array_BST::insert(const int &data)
{
    int i=1;
    if (array[1]==0) {
        array[1] = data;
        Height  = 1;
    }
    else {
        while (array[i]!=0) {
            if (data<array[i]) i = 2*i;
            else if (data>array[i]) i = 2*i + 1;
            else return;
        }
        array[i] = data;
        if (i>=pow(2, Height)) Height++;
    }

}
bool Array_BST::search(const int &data) const
{
    int i=1;
    while (array[i]!=0) {
        if (data<array[i]) i = 2*i;
        else if (data>array[i]) i = 2*i + 1;
        else return true;
    }
    return false;
}
List_BST::List_BST()
{
    root = nullptr;
}
ListNode* List_BST::createLeaf(int key) const
{
    return new ListNode(key);
}
void List_BST::insert(const int & data)
{
    if (root==nullptr) {
        Height = 1;
        root = createLeaf(data);
    } else {
        ListNode* tmp = root;
        ListNode* tmp_l=nullptr;
        int h=1;
        while (tmp!=nullptr) {
            tmp_l = tmp;
            if (data<tmp->key) tmp = tmp->left;
            else if (data>tmp->key) tmp = tmp->right;
            else return;
            h++;
        }
        if (data<tmp_l->key) tmp_l->left = createLeaf(data);
        else if (data>tmp_l->key) tmp_l->right = createLeaf(data);

        if (h>Height) Height = h;
    }
}
bool List_BST::search(const int& data) const
{
    ListNode* tmp = root;
    while (tmp!=nullptr) {
        if (data<tmp->key) tmp = tmp->left;
        else if (data>tmp->key) tmp = tmp->right;
        else return true;
    }
    return false;

}
void List_BST::deleteTree(ListNode *root)
{
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }

}
