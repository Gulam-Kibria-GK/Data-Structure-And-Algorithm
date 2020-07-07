#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *next;
};

struct node *news(int valu)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    return temp;
}

void push(struct node **head,int item)
{
    struct node *temp=news(item);
    temp->next=*head;
    *head=temp;
}

int isEmpty(struct node *head)
{
    return !head;
}

int pop(struct node **head)
{
    if(isEmpty(*head))
    {
        cout<<"overflow"<<endl;
        return 1;
    }
    struct node *t=*head;
    int tt=t->data;
    *head=(*head)->next;
    return tt;
}

int main()
{
    struct node *head=NULL;

    int a;
    cin>>a;
    while(a>0)
    {
        push(&head,a);
        cin>>a;
    }

    cout<<"poping........"<<endl;
    while(!isEmpty(head))
    {
        printf("%d\n",pop(&head));
    }
}
