#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
};

struct node *news(int a)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}

struct node *inser(struct node *head,int a)
{
    if(head==NULL)
        return news(a);
    if(a>head->data)
    {
        head->r=inser(head->r,a);
    }
    else if(a<head->data)
    {
        head->l=inser(head->l,a);
    }
    return head;
}


void in(struct node *head)
{

    if(head==NULL)
        return;
    in(head->l);
    printf("%d\n",head->data);
    in(head->r);
}

void pre(struct node *head)
{
    if(head==NULL)
        return;
        printf("%d\n",head->data);
       pre(head->l);
       pre(head->r);
}


void post(struct node *head)
{
    if(head==NULL)
        return;
       post(head->l);
       post(head->r);
       printf("%d\n",head->data);
}


//search in tree-----------

struct node *sea(struct node *head,int a)
{
    if(head==NULL)
        return 0;
    if(a<head->data)
        sea(head->l,a);
    else if(a>head->data)
        sea(head->r,a);
    else if(a==head->data)
        return head;

}


struct node *minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->l != NULL)
        current = current->l;

    return current;
}

struct node *deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->l = deleteNode(root->l, key);

    else if (key > root->data)
        root->r = deleteNode(root->r, key);

    else
    {
        if (root->l == NULL)
        {
            struct node *temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL)
        {
            struct node *temp = root->l;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->r);
        root->data = temp->data;
        root->r = deleteNode(root->r, temp->data);
    }
    return root;
}


void del_all(struct node *root)
{
    if(root != NULL)
    {
        del_all(root->l);
        del_all(root->r);
        free(root);
    }
}



int main()
{
    struct node *head=NULL;
    int a,i;
    cout<<"how much data needed in a tree........: ";
    cin>>i;
    i--;
    cin>>a;
    head=inser(head,a);
    while(i--)
    {
        cin>>a;
        inser(head,a);
    }
    inser(head,100);
    inser(head,200);
    inser(head,300);
    inser(head,400);
    inser(head,500);
    inser(head,1000);

    cout<<"preorder........."<<endl;
    pre(head);
    cout<<endl<<"inorder.........."<<endl;
    in(head);
    cout<<endl<<"postorder........"<<endl;
    post(head);


    int n;
    printf("Enter A Number You Want To Search.\n");
    cin>>n;
    struct node *temp=NULL;
    temp=sea(head,n);
    if(temp)
    {
        printf("Searched node = %d\n",temp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }


    printf("\nDelete 100\n");
    head = deleteNode(head, 100);
    printf("Inorder traversal of the modified tree \n");
    in(head);

    printf("\nDelete 300\n");
    head = deleteNode(head, 300);
    printf("Inorder traversal of the modified tree \n");
    in(head);

    printf("\nDelete 500\n");
    head = deleteNode(head, 500);
    printf("Inorder traversal of the modified tree \n");
    in(head);


    del_all(head);
    printf("\nDelete all root.\n.....\n.....\n.....\n");

    return 0;
}
