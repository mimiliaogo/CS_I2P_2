#include<stdio.h>
#include <stdlib.h>
#include"function.h"
#include "function.c"
int main(void)
{
//    freopen("123.txt", "r", stdin);
	Node *head=NULL;
	size_t N;
	scanf("%d",&N);
	while(N--)
	{
		char op;
		unsigned short val;
		size_t pos,begin_pos,end_pos;
		scanf(" %c",&op);
		switch(op)
		{
		case 'I':
			scanf("%u %u",&pos,&val);
			do_I(&head,pos,val);
			break;
		case 'E':
			scanf("%u %u",&begin_pos,&end_pos);
			do_E(&head,begin_pos,end_pos);
			break;
		case 'P':
			scanf("%u",&pos);
			do_P(head,pos);
			break;
		case 'R':
			scanf("%u",&val);
			do_R(&head,val);
			break;
		case 'S':
			do_S(head);
			break;
		}
	}
            return 0;
}
