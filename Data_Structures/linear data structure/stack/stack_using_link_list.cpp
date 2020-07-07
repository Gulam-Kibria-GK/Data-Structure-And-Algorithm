#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *top;

void push(int a)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=top;
    top=temp;
}
int isempty()
{
    return !top;
}

int pop()
{
    if(isempty())
    {
        cout<<"stack is underflow"<<endl;
        return 0;
    }
    struct node *temp=top;
    int item=temp->data;
    top=top->next;
    free(temp);
    return item;
}
int main()
{
    top=NULL;
    int i=0,a;
    cin>>a;
    while(a>0)
    {
        push(a);
        cin>>a;
    }
    cout<<endl<<"pop stack"<<endl;
    while(!isempty())
    {
        printf("%d\n",pop());
    }
}
