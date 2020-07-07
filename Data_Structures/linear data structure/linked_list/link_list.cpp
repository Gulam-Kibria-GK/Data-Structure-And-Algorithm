#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head;

//print.........................

void print()
{
    struct node *tem;
    tem=head;
    while(tem!=NULL)
    {
        printf("%d ",tem->data);
        tem=tem->next;
    }
    printf("\n");
}
//push........................

void insertinfast(int valu)
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
        struct node *temp2;
        temp2=head;
        head=temp;
        temp->next=temp2;
    }
}
//append........assignin_data..........are same.....

void insertinlast(int valu)
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
        struct node *temp2;
        temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}

//insert_in_after_position..................

void insertin_after_position(int valu,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    int i;
    struct node *temp2;
    struct node *temp3;
    temp2=head;
    for(i=1; i<=n-2; i++)
    {
        temp2=temp2->next;
    }
    temp3=temp2->next;
    temp2->next=temp;
    temp->next=temp3;
}

//insertin_befor_position...............

void insertin_befor_position(int valu,int n)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    int i;
    struct node *temp2;
    struct node *temp3;
    temp2=head;
    for(i=1; i<=n-1; i++)
    {
        temp2=temp2->next;
    }
    temp3=temp2->next;
    temp2->next=temp;
    temp->next=temp3;
}

//deletein_position_valu................

void deletein_position(int valu1)
{
    if(valu1==1)
    {
        struct node* temp;
        temp=head;
        head=temp->next;
        free(temp);
    }
    else
    {

        struct node* temp;
        temp=head;
        int i;
        for(i=1; i<=valu1-2; i++)
        {
            temp=temp->next;
        }
        struct node* temp2;
        temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }
}

//assignin_data...................

void assignin_data(int valu)
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
    struct node *n1=(struct node*)malloc(sizeof(struct node));
    struct node *n2=(struct node*)malloc(sizeof(struct node));
    struct node *n3=(struct node*)malloc(sizeof(struct node));
    struct node *n4=(struct node*)malloc(sizeof(struct node));
    struct node *n5=(struct node*)malloc(sizeof(struct node));
    head=n1;
    n1->data=10;
    n1->next=n2;
    n2->data=20;
    n2->next=n3;
    n3->data=30;
    n3->next=n4;
    n4->data=50;
    n4->next=n5;
    n5->data=66;
    n5->next=NULL;
    assignin_data(1);
    assignin_data(5);
    assignin_data(10);
    assignin_data(12);
    assignin_data(15);
    assignin_data(18);

    print();

    //insertinfast();
   //print();

    //insertinlast();
   // print();

    //insertin_after_position();
   // print();

    //insertin_befor_position():
   // print();

    //deletein_position();
   //print();

   return 0;
}
