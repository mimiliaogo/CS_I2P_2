#include <iostream>
#include "function.h"
#include <vector>
using namespace std;
/*Why use iterator? why not recursion?
:for user*/
/*void* data
About type: float* pi;
data type decide dereference and pi++ (+多少?)
*/
enum STATE {SELF, LEFT, RIGHT};
//把自己印出去 /印出左樹了 /印出右樹了
struct Content
{
    // something
    Node* nd;
    STATE st;
    
    Content():nd(nullptr), st(SELF){};
    Content(Node* input):nd(input), st(SELF){};
};

Iterator::Iterator(Node *root)
{
   vector<Content*> *v  = new vector<Content*>;
   if (root!=nullptr) {
       v->push_back(new Content(root));
   }
   data = v;
}

Iterator::Iterator(const Iterator &other)
{
    data = new vector<Content*>(*static_cast<vector<Content*>)
}

Iterator::~Iterator()
{
   delete static_cast<vector<Content*>*>(data);
}

int Iterator::operator*() const
{
    vector<Content*> *v = static_cast<vector<Content*>*> data;
    if (v->size()==0) {
        return 0;
    } else {
        return v->back()->nd->value;
    }
}

bool Iterator::operator!=(const Iterator &it) const
{
   
}

void Iterator::operator++(int)
{

}

