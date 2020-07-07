#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* head;

void print()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void inser(int valu)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void inserinsort(int mun)
{
    struct node * temp=(struct node *)malloc( sizeof(struct node));
    temp->data=mun;
    temp->next=NULL;
    if(head == NULL || head->data > temp->data )
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        struct node *tem;
        struct node *paa;
        tem=head;
        paa=tem->next;
        while(paa!=NULL && paa->data < temp->data)
        {
            tem=paa;
            paa=paa->next;
        }
        tem->next=temp;
        temp->next=paa;
    }

}


int main()
{
    head=NULL;
    inser(10);
    inser(15);
    inser(20);
    inser(22);
    inser(23);

    print();

    inserinsort(13);
    print();
}
