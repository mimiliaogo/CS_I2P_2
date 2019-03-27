#include <stdio.h>
#include <stdlib.h>
#include "11270.h"

Node* createList(){
    Node *head=NULL;
    int data;

    scanf("%d", &data);

    if (data == -1) // stop the reading
        return NULL;

    // your code here
    return head;

}

Node* reverse(Node* p){
    Node *temp, *head;

    if (p == NULL){ // handle the special case
        return NULL;
    } else if (p->next == NULL) { // the last element,
        // now we can make it the first element
        return p;
    } else { // p->next is not NULL, pointing to a Node.
        // your code here.
    }
    return head;

}

void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

    head = createList();
	head = reverse(head);
	printList(head);
	freeList(head);
	return 0;
}

void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
