#include <iostream>
#include <string.h>

using namespace std;
int cnt=0;
int pos=0;
using Node = struct _node {
    int data;
    struct _node* next;
    struct _node* prev;
};
//testing
void showNode(Node* head) {
    Node* tmp = head;
    for (tmp = head; tmp!=nullptr; tmp = tmp->next) {
        cout<<tmp->data<<' ';
    }
    cout<<endl;
}
void InsertHead(Node* &head, Node* &tail, Node* &mid, int data){
    Node* tmp;
    if (head == nullptr) {
        head = new Node;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        mid = head;
		cnt=1;
		pos=1;
    } else {
        tmp = new Node;
        tmp->data = data;
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
        cnt++;
        pos++;
        if (pos>cnt/2+1) {
            pos--;
            mid = mid->prev;
        }
    }
}
void InsertTail(Node* &head, Node* &tail, Node* &mid, int data){
    Node* tmp;
    if (tail == nullptr) {
        tail = new Node;
        tail->data = data;
        tail->prev = nullptr;
        tail->next = nullptr;
        head = tail;
        mid = head;
        cnt = 1;
        pos = 1;
    } else {
        tmp = new Node;
        tmp->data = data;
        tmp->next = nullptr;
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        cnt++;
        if (pos<cnt/2+1) {
            pos++;
            mid = mid->next;
        }
    }
}
int RemoveHead(Node* &head, Node* &tail, Node* &mid){
    Node* temp;
    int data = 0;
    if (head == nullptr){
        throw out_of_range ("empty list");
    } else {
        data = head->data;
        temp = head;
        if (head->next==nullptr) {//ONlY ONE
            head = nullptr;
            tail = nullptr;
            mid = nullptr;
            pos = 0;
            cnt = 0;
            delete temp;
        }
        else {
            head = head->next;
            head->prev= nullptr;
            delete temp;
            cnt--;
            pos--;
            if (pos<cnt/2+1) {
                pos++;
                mid = mid->next;
            }
        }

    }
     return data;
}



int RemoveTail(Node* &head, Node* &tail, Node* &mid){
    Node* temp;
    int data = 0;
    if (tail == nullptr){
        throw out_of_range ("empty list");
    } else {
        data = tail->data;
        temp = tail;
        if (tail->prev==nullptr) {
            head = nullptr;
            tail = nullptr;
            mid = nullptr;
            pos =  0;
            cnt = 0;
            delete temp;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            cnt--;
            if (pos>cnt/2+1) {
                pos--;
                mid = mid->prev;
            }
        }

    }
    return data;
}

void Swap(Node* &head, Node* &tail, Node* &mid){
    Node* tmp_tail=tail;
    Node* tmp_head = head;
    // count the number of nodes

    // if cnt == 0 or cnt == 1, do nothing
    if (cnt>1) {
        // find the middle node

        // link the head and tail to form
        // a circular doubly linked list
        tail->next = head;
        head->prev = tail;
        // break the circular list from the middle node
        head = mid;
        tail = mid->prev;
        head->prev = nullptr;
        tail->next = nullptr;
        if (cnt%2!=0) mid = tmp_tail;
        else mid = tmp_head;
    }
}

int main(){
    Node *head=nullptr, *tail=nullptr, *mid=nullptr;
    char cmd[4];
    int data;

    while(cin >> cmd){
        if(strcmp(cmd, "IH")==0){ // insert an integer to the head
            cin>>data;
            InsertHead(head, tail, mid, data);
        } else if (strcmp(cmd, "IT")==0){ // insert an integer to the end
            cin>>data;
            InsertTail(head, tail, mid, data);
        } else if (strcmp(cmd,"RH")==0){   // print and remove a node from head
            try {
                cout<<RemoveHead(head, tail, mid)<<endl;
            } catch(out_of_range &e) {
                cout<<endl;
            }
        } else if (strcmp(cmd, "RT") == 0) {// print and remove a node from tail
            try {
                cout<<RemoveTail(head, tail, mid)<<endl;
            } catch(out_of_range &e) {
                cout<<endl;
            }
        } else if (strcmp(cmd, "S")==0){
            Swap(head, tail, mid);
        }
//        showNode(head);
    }
}
