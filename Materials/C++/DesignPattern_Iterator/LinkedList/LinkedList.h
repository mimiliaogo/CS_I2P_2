#include <iostream>
using namespace std;


namespace I2P {

    class LLIterator;

    class LinkedList{

        struct Node{
			Node *next;
			int data;
		};
		Node *head, *tail;

    public:
        friend class LLIterator;

        LinkedList(){
            head = nullptr;
            tail = head;
        }

        ~LinkedList(){
            for(tail=head; tail!=nullptr; tail = tail->next){
                head = head->next;
                delete tail;
                tail = head;
            }
        }

        void pushBack(int in){ // push an element to the end of linked list
            if(tail == nullptr) {
                head = new Node();
                tail = head;
            } else {
                tail->next = new Node();
                tail = tail->next;
            }
            tail->data = in;
            tail->next = nullptr;
        }


        LLIterator *createIterator() const;   // Add a createIterator() member
    };

    class LLIterator {  // Design an "iterator" class
        const LinkedList *L;
        LinkedList::Node *curr;

    public:
        LLIterator(const LinkedList *ll){
            L = ll;
            curr = L->head;
        }
        void first() {
            curr = L->head;
        }

        void next() {
            if (curr!=nullptr)
                curr = curr->next;
        }

        bool isDone() {
            return curr==nullptr;
        }

        int currentItem(){
            if (curr!=nullptr)
                return curr->data;
            else
                throw "Null data\n";
        }
    };

    LLIterator *LinkedList::createIterator() const {  // Add a createIterator() member
        return new LLIterator(this);
    }
}
