#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char data[21];
    struct _Node *next;
    struct _Node *prev;
} Node;

int main()
{
    int times;
    char cmd[3];
    Node *head=NULL, *tail=NULL, *temp, *temp2;

    scanf("%d",&times);
    while(times--)
    {
        scanf("%s", cmd);
        // insert a node
        if(strncmp (cmd,"I",2)==0)
        {
            // your code
        }
        else if(strncmp (cmd,"RA",2)==0)
        {
            // your code
        }
        else if(strncmp (cmd,"DA",2)==0)
        {
            // your code
        }
        else if(strncmp (cmd,"S",2)==0)
        {
            // your code
        }
    }
    for (temp=head; temp!=NULL; temp = temp->next){
        free(head);
        head = temp;
    }

    return 0;
}
