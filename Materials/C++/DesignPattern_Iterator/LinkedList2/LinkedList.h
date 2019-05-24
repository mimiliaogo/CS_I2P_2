#include <iostream>
using namespace std;

namespace I2P2017 {

    class LinkedList{

        struct Node{
			Node *next;
			int data;
		};
		Node *head, *tail;

    public:
        friend class LLIterator;

        class LLIterator { //nested class -->make for LinkedList
            LinkedList::Node *curr;
        public:
            LLIterator() {
                curr = nullptr;
            }

            LLIterator(LinkedList::Node *head) {
                curr = head;
            }

            LLIterator(const LLIterator& it) {
                curr = it.curr;
            }

            ~LLIterator(){
                curr = nullptr;
            }

            LLIterator& operator=(const LLIterator& it){
                curr = it.curr;
            }

            bool operator!=(const LLIterator& it){
                return curr != it.curr;
            }

            // define operator ++ for linked list iterator
            LLIterator& operator++(){
                if (curr != nullptr)
                    curr = curr->next;
                return *this;
            }

            int& operator*() {
                if (curr!=nullptr)
                    return curr->data;
                else
                    throw "null data \n";
            }
        };

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

        LLIterator begin(){
            return head;
        }

        LLIterator end(){
            return nullptr;
        }
    };

}
