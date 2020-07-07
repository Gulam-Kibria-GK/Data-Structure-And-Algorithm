#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *l,*r;
};

struct node *news(int a)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}

struct node *inser(struct node *root,int data)
{
    if(root==NULL)
        return news(data);
    if(data<root->data)
        root->l=inser(root->l,data);
    else if(data>root->data)
    root->r=inser(root->r,data);

    return root;
}


void inorder( struct node *root)
{
    if(root==NULL)
     return;
        inorder(root->l);
        printf("%d\n",root->data);
        inorder(root->r);
}


int main()
{
    struct node *root=NULL;
    root=inser(root,50);
    inser(root,30);
    inser(root,20);
    inser(root,40);
    inser(root,70);
    inser(root,60);
    inser(root,80);


    inorder(root);
}
