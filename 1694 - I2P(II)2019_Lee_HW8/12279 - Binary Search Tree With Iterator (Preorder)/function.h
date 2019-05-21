#pragma once

struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int v)
        :value(v)
        ,right(nullptr)
        ,left(nullptr) {}

    ~Node()
    {
        delete right;
        delete left;
    }
};

class Iterator
{
public:
    Node *data;

    Iterator(Node *);
    Iterator(const Iterator &other);
    ~Iterator();
    int operator*() const;
    bool operator!=(const Iterator &) const;
    void operator++(int);
};


class BST
{
public:
    BST():m_root(nullptr){}
    ~BST(){delete m_root;}

    void push_back(int val)
    {
        Node **pos = &m_root;

        while( *pos )
        {
            if( (*pos)->value < val ) pos = &(*pos)->right;
            else pos = &(*pos)->left;
        }

        *pos = new Node(val);
    }

    Iterator begin()
    {
        Iterator it(m_root);
        return it;
    }

    Iterator end()
    {
        Iterator end(nullptr);
        return end;
    }

private:
    Node *m_root;
};

