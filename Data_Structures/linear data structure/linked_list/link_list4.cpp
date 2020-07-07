#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node * head;
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

void inser1(int item)
{
    struct node *temp=(struct node *)malloc( sizeof(struct node));
    temp->data=item;
    temp->next=head;
    head=temp;
}

int main()
{
    head=NULL;
    inser1(90);
    inser1(80);
    inser1(70);
    inser1(100);
    inser1(80);

    print();
    return 0;

}
