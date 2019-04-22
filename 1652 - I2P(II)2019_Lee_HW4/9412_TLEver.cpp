#include <iostream>
#include <string.h>

using namespace std;

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
void InsertHead(Node* &head, Node* &tail, int data){
    Node* tmp;
    if (head == nullptr) {
        head = new Node;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    } else {
        tmp = new Node;
        tmp->data = data;
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}

void RemoveHead(Node* &head, Node* &tail){
    Node* temp;

    if (head == nullptr){
        cout << endl;
    } else {
        cout << head->data<<endl;
        temp = head;
        if (head->next==nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev= nullptr;
        }
        free(temp);
    }
}

void InsertTail(Node* &head, Node* &tail, int data){
    Node* tmp;
    if (tail == nullptr) {
        tail = new Node;
        tail->data = data;
        tail->prev = nullptr;
        tail->next = nullptr;
        head = tail;
    } else {
        tmp = new Node;
        tmp->data = data;
        tmp->next = nullptr;
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

void RemoveTail(Node* &head, Node* &tail){
    Node* temp;

    if (tail == nullptr){
        cout << endl;
    } else {
        cout << tail->data <<endl;
        temp = tail;
        if (tail->prev==nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        free(temp);
    }
}

void Swap(Node* &head, Node* &tail){
    int i, cnt=0, mid;
    Node* temp;

    // count the number of nodes
    for (temp = head; temp!=nullptr; temp = temp->next) cnt++;
    // if cnt == 0 or cnt == 1, do nothing
    if (cnt>1) {
        // find the middle node
        mid = cnt/2;
        temp = head;
        for (i=0; i<mid; i++) {
            temp = temp->next;
        }
        // link the head and tail to form
        // a circular doubly linked list
        tail->next = head;
        head->prev = tail;
        // break the circular list from the middle node
        head = temp;
        tail = temp->prev;
        head->prev = nullptr;
        tail->next = nullptr;

    }
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    char cmd[4];
    int data;

    while(cin >> cmd){
        if(strcmp(cmd, "IH")==0){ // insert an integer to the head
            cin>>data;
            InsertHead(head, tail, data);
        } else if (strcmp(cmd, "IT")==0){ // insert an integer to the end
            cin>>data;
            InsertTail(head, tail, data);
        } else if (strcmp(cmd,"RH")==0){   // print and remove a node from head
            RemoveHead(head, tail);
        } else if (strcmp(cmd, "RT") == 0) {// print and remove a node from tail
            RemoveTail(head, tail);
        } else if (strcmp(cmd, "S")==0){
            Swap(head, tail);
        }
//        showNode(head);
    }
}
