
#include <iostream>
#include "function.h"
#include <stack>
using namespace std;

struct Content
{
    // something
    stack<Node*> st;
};

Iterator::Iterator(Node *root)
{
    // data = new Content;
    data = new Content;
    ((Content*)(data))->st.push(nullptr);
    ((Content*)(data))->st.push(root);
}

Iterator::Iterator(const Iterator &other)
{
    ((Content*)(data))->st = ((Content*)(other.data))->st;
}

Iterator::~Iterator()
{
    data = nullptr;

}

int Iterator::operator*() const
{
    return ((Content*)data)->st.top()->value;
}

bool Iterator::operator!=(const Iterator &it) const
{
    return ((Content*)data)->st.top()!=((Content*)(it.data))->st.top();
}

void Iterator::operator++(int)
{
    Node* root = ((Content*)data)->st.top();
    ((Content*)data)->st.pop();
    if (root->right) ((Content*)data)->st.push(root->right);
    if (root->left)((Content*)data)->st.push(root->left);

}
