#include<bits/stdc++.h>
using namespace std;


/**********************
this is a tree.....apply (pre,in,post)order
                    e
                   / \
                  f   \
                 / \   \
                h   i   \
               / \       g
              a   b     / \
             / \       j   k
            c   d

************************/



struct node
{
    char data;
    struct node *l;
    struct node *r;
};

struct node *news(char a)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->l=temp->r=NULL;
    return temp;
}

void pre(struct node *head)
{
    if(head==NULL)
        return;
    printf("%c\n",head->data);
    pre(head->l);
    pre(head->r);
}
void in(struct node *head)
{
    if(head==NULL)
        return;
    in(head->l);
    printf("%c\n",head->data);
    in(head->r);
}

void post(struct node *head)
{
    if(head==NULL)
        return;
    post(head->l);
    post(head->r);
    printf("%c\n",head->data);
}

int main()
{
    char i,a;
    struct node *head=NULL;
    struct node *n1=news('a');
    struct node *n2=news('b');
    struct node *n3=news('c');
    struct node *n4=news('d');
    head=news('e');
    head->l=news('f');
    head->r=news('g');
    head->l->l=news('h');
    head->l->r=news('i');
    head->r->l=news('j');
    head->r->r=news('k');
    head->l->l->l=n1;
    head->l->l->r=n2;
    n1->l=n3;
    n1->r=n4;

    cout<<"preorder........."<<endl;
    pre(head);
    cout<<endl<<"inorder.........."<<endl;
    in(head);
    cout<<endl<<"postorder........"<<endl;
    post(head);

    return 0;
}

