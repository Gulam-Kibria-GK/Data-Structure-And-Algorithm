#include<stdio.h>
//#include<iostream>
//#include<bits/stdc++.h>
//using namespace std;
#include<stdlib.h>
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

int main()
{
    head = NULL;
    head =(struct node *) malloc(sizeof(struct node));
    head->data=5;

    head->next=(struct node *)malloc(sizeof(struct node));
    head->next->data=10;
    head->next->next=(struct node *)malloc(sizeof(struct node));
    head->next->next->data=15;
    head->next->next->next=NULL;
    printf();
    return 0;
}
