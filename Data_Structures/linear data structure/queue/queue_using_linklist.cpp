#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *next;
};

struct node2
{
    struct node *f;
    struct node *r;
};

struct node *news(int valu)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=valu;
    temp->next=NULL;
    return temp;
}

struct node2 *news2()
{
    struct node2 *t=(struct node2 *)malloc(sizeof(struct node2));
    t->f=NULL;
    t->r=NULL;
    return t;
}

int isEmpty(struct node2 *temp)
{
    return(temp->f==NULL);
}
void enqueu(struct node2 *temp,int valu )
{
    struct node *t=news(valu);
    if(temp->r==NULL)
    {
        temp->f=t;
        temp->r=t;
        return;
    }
    temp->r->next=t;
    temp->r=t;
}

int dequeue(struct node2 *temp)
{
    if(isEmpty(temp))
    {
        cout<<"full"<<endl;
        return 1;
    }
    int  item=temp->f->data;
    struct node *t=temp->f;
    temp->f=t->next;
    if(temp->f==NULL)
    {
        temp->r=NULL;
    }
    free(t);
    return item;
}

int main()
{
    struct node2 *temp=news2();
    int data;
    cin>>data;
    while(data>0)
    {
        enqueu(temp,data);
        cin>>data;
    }
    cout<<"dequeing......."<<endl;
    while(!isEmpty(temp))
    {
        printf("%d\n",dequeue(temp));
    }
}











