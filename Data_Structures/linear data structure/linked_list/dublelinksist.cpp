//doubly push ;

#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *makeNode(int item)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->prev = NULL;
    p->data = item;
    p->next = NULL;
    return p;
}

void traverse (struct node *head)
{
     struct node *ptr=head;
     while(ptr!=NULL)
     {
         printf("%d ",ptr->data);
         ptr=ptr->next;
     }
}

void push(struct node **headRef,int item)
{
    struct node *temp=makeNode(item) ;
    temp->prev = NULL;
    temp->data = item;
    temp-> next = *headRef;

    *headRef = temp;
}

int main()
{
    struct node *head=NULL;
    int number ;
    scanf("%d",&number);
    while (number!=0)
    {
        push (&head,number);
        scanf("%d",&number);
    }
    traverse(head);
}

