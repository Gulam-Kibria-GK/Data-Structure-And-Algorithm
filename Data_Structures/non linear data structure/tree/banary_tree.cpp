#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
};

struct node *news(int valu)
{
    struct node *temp=(struct node*)malloc( sizeof(struct node));
    temp->data=valu;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}

void post(struct node *root)
{
    if(root==NULL)
        return;
    post(root->l);
    post(root->r);
    printf("%d\t",root->data);
}

void in(struct node *root)
{
    if(root==NULL)
        return;
    in(root->l);
    printf("%d\t",root->data);
    in(root->r);
}

void pre(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    pre(root->l);
    pre(root->r);
}

int main()
{
    struct node *root=news(1);
    root->l=news(2);
    root->r=news(3);
    root->l->l=news(4);
    root->l->r=news(5);

    printf("Preorder.....\n");
    pre(root);
    printf("\n\nInorder......\n");
    in(root);
    printf("\n\nPostorder....\n");
    post(root);
}
