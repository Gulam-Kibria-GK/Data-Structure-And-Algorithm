// Binary search tree:
// Created by Mobin:
#include<stdio.h>
#include<stdlib.h>
struct btre
{
    struct btre *left;
    int data;
    struct btre *right;
};
struct btre *makenode(int n)
{
    struct btre *p=(struct btre *)malloc(sizeof(struct btre));
    p->left=NULL;
    p->data=n;
    p->right=NULL;
    return p;
}
struct btre *push(struct btre *n,int item)
{
    if(n==NULL)
    {
        return (makenode(item));
    }
    if(item<n->data)
    {
        n->left=push(n->left,item);
    }
    else if(item>n->data)
    {
        n->right=push(n->right,item);
    }
    return n;

}
void in(struct btre *m)
{
    if(m==NULL)
    {
        return;
    }
    in(m->left);
    printf("%d\n",m->data);
    in(m->right);
}
void pre(struct btre *m)
{
    if(m==NULL)
    {
        return;
    }
    printf("%d\n",m->data);
    pre(m->left);
    pre(m->right);
}
void post(struct btre *m)
{
    if(m==NULL)
    {
        return;
    }
    post(m->left);
    post(m->right);
    printf("%d\n",m->data);
}
int main()
{
    struct btre *muk=NULL;
    int data;
    scanf("%d",&data);
    muk=push(muk,data);
    while(data>0)
    {
        scanf("%d",&data);
        push(muk,data);

    }
    printf("inOrdering past.....\n");
    in(muk);
    printf("preOrdering past.....\n");
    pre(muk);
    printf("postOrdering past.....\n");
    post(muk);
}
