#ifndef NODE
#define NODE
#include<stddef.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val);
void do_E(Node **head,size_t begin_pos,size_t end_pos);
void do_P(Node  *head,size_t pos);
void do_R(Node **head,unsigned short val);
void do_S(Node  *head);

#endif
