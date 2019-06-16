#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node():data(0), left(nullptr), right(nullptr) {};
    Node(int a):data(a), left(nullptr), right(nullptr) {};

};
Node* BSTInsert (Node* root, int data) {

    if (root==nullptr) root = new Node(data);
    else {
        if (data<root->data) root->left =  BSTInsert(root->left, data);
        else if (data>root->data) root->right =  BSTInsert(root->right, data);
    }
    return root;

}
Node* BSTConstruct() {
    Node* root=nullptr;
    int num, data;
    cin>>num;

    while (num>0) {
        num--;
        cin>>data;
        root = BSTInsert(root, data);
    }

    return root;
}
void PrintInOrder(Node* root) {

    if (root!=nullptr) {
        PrintInOrder(root->left);
        cout<<root->data<<' ';
        PrintInOrder(root->right);
    }

}
int GetMax(Node* root) {
    if (root==nullptr) return 0;
    int lrm;
    lrm = max(GetMax(root->left), GetMax(root->right));
    return lrm + 1;

}
int SumLevel(Node* root, int level) {

    if (root==nullptr) return 0;
    if (level==1) return root->data;
    else {
        return SumLevel(root->left, level-1) + SumLevel(root->right, level-1);
    }

}
int NumLevel(Node* root, int level) {

    if (root==nullptr) return 0;
    if (level==1) return 1;
    else {
        return NumLevel(root->left, level-1) + NumLevel(root->right, level-1);
    }

}

int main()
{
    //freopen ("12193.txt","r",stdin);
    Node* root=nullptr;
    root = BSTConstruct();
    int n, lev;
    string cmd;
    cin>>n;
    while (n>0) {
        n--;
        cin>>cmd;
        if (cmd=="P") {
            if (root==nullptr) cout<<"NULL";
            else PrintInOrder(root);
            cout<<endl;
        }
        else if (cmd=="GetMax") cout<<GetMax(root)<<endl;
        else if (cmd=="SumLevel") {
           cin>>lev;
            if (lev>GetMax(root)||lev==0) cout<<0<<endl;
            else cout<<SumLevel(root, lev)<<endl;

        }
        else if (cmd=="AverLevel")  {
            cin>>lev;
            if (lev>GetMax(root)||lev==0) cout<<0<<endl;
            else cout<<setprecision(3)<<fixed<<static_cast<float>(SumLevel(root, lev))
            /static_cast<float>(NumLevel(root, lev))<<endl;

        }

    }


}
