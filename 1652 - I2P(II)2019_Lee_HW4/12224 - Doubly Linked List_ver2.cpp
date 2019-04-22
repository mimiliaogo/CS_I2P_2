#include <iostream>
#include <string>
namespace OJ12224 {
    class ListNode {
    private:
        int data;
        ListNode* next;
        ListNode* prev;
    public:
        ListNode():data(0),next(nullptr),prev(nullptr){};//default
        ListNode(int n):data(n),next(nullptr),prev(nullptr){};
        friend class List;
    } ;

    class List{
        private:
            int cnt;//number of nodes
            int pos;//pos of middle
            ListNode* head;
            ListNode* tail;
            ListNode* middle;
            void reset() {
                head = nullptr;
                tail = nullptr;
                middle = nullptr;
                cnt = 0;
                pos = 0;
            }
            void clean() {
                ListNode* temp;
                while (head!=nullptr) {
                    temp = head;
                    head = head->next;
                    delete temp;
                }
            }
        public:
            List() {
                reset();
            };
            ~List() {
                clean();
            };
            void InsertHead(int data);
            void InsertTail(int data);
            int RemoveHead();
            int RemoveTail();
            void Swap();
            void showNode();
    };
}
using namespace std;
using namespace OJ12224;
void List::InsertHead(int data)
{
    if (head==nullptr) {
        head = new ListNode(data);
        head->prev=nullptr;
        head->next = nullptr;
        tail = head;
        middle = head;
        cnt = 1;
        pos = 1;
    } else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        cnt++;
        pos++;
        if (pos>cnt/2+1) {
            pos--;
            middle = middle->prev;
        }
    }
}
void List::InsertTail(int data)
{
    if (tail==nullptr) {
        tail = new ListNode(data);
        tail->next = nullptr;
        tail->prev = nullptr;
        head = tail;
        middle = tail;
        cnt = 1;
        pos = 1;
    } else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail = tail->next;
        cnt++;
        if (pos<cnt/2+1) {
            pos++;
            middle = middle->next;
        }
    }
}
int List::RemoveHead()
{
    int data=0;
    ListNode* temp=nullptr;
    if (head==nullptr) {
        throw out_of_range("empty list");
    } else {
        data = head->data;
        temp = head;
        if (head->next==nullptr){
            pos = 0;
            cnt = 0;
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
            cnt--;
            pos--;
            if (pos<cnt/2+1) {
                pos++;
                middle = middle->next;
            }
        }
        delete temp;
    }
    return data;
}
int List::RemoveTail()
{
    int data=0;
    ListNode* temp=nullptr;
    if (tail==nullptr) {
        throw out_of_range ("empty list");
    } else {
        data = tail->data;
        temp = tail;
        if (tail->prev==nullptr) {
            cnt = 0;
            pos = 0;
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
            cnt--;
            if (pos>cnt/2+1) {
                pos--;
                middle = middle->prev;
            }
        }
        delete temp;
    }
    return data;
}
void List::Swap()
{
    ListNode* tmp_head=head, *tmp_tail=tail;
    if (cnt>1) {
        head->prev = tail;
        tail->next = head;
        head = middle;
        tail = middle->prev;
        if (cnt%2==0) {
            middle = tmp_head;
        } else {
            middle = tmp_tail;
        }
        head->prev = nullptr;
        tail->next = nullptr;
    }
}
void List::showNode() {
    ListNode* temp = head;
    while (temp!=nullptr) {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    List L;
    string cmd;
    int data;
    while (cin>>cmd) {
        if (cmd=="IH") {
            cin>>data;
            L.InsertHead(data);
        } else if (cmd=="IT") {
            cin>>data;
            L.InsertTail(data);
        } else if (cmd=="RH") {
            try {
                cout<<L.RemoveHead()<<endl;
            } catch(const out_of_range &e) {
                cout<<endl;
            }
        } else if (cmd=="RT") {
            try {
                cout<<L.RemoveTail()<<endl;
            } catch(const out_of_range &e) {
                cout<<endl;
            }
        } else if (cmd=="S") {
            L.Swap();
        }
//        L.showNode();
    }
}
