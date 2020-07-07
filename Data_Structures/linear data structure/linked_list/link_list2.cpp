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
    return 0;
}

