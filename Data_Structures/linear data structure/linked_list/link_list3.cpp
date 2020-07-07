#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* head;


void printf()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}


void inser(int valu)
{
    struct node * temp=(struct node*)malloc( sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;

    }
    else
    {
        struct node *t;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
}
void delet(int valu1)
{
    if(valu1==1)
    {
        struct node* temp;
        temp=head;
        head=temp->next;
        free(temp);
    }
    //else if()
    else
    {
        struct node* temp;
        temp=head;
        int i;
        for(i=1;i<=valu1-2;i++)
        {
            temp=temp->next;
        }
        struct node* temp2;
        temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }
}


int main()
{
    head=NULL;
    inser(1);
    inser(5);
    inser(10);
    inser(12);
    inser(15);
    inser(18);

    printf();

    delet(4);
    printf();

    delet(1);
    printf();

    delet(3);
    printf();

    delet(1);
    printf();

    return 0;
}


