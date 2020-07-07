#include<stdio.h>
#include<stdlib.h>

struct stackNode
{
    int data;
    struct stackNode *next;
};

struct stackNode *makeStack(int item)
{
    struct stackNode *temp =
        (struct stackNode *)malloc(sizeof(struct stackNode));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

void push(struct stackNode **headRef, int item)
{
    struct stackNode *temp = makeStack(item);
    temp->next = *headRef;
    *headRef = temp;
}

int isEmpty(struct stackNode *head)
{
    return !head;
}

int pop(struct stackNode **headRef)
{
    if( isEmpty(*headRef) )
    {
        printf("Stack Underflow.\n");
        return 1;
    }
    struct stackNode *temp = *headRef;
    int item = temp->data;
    *headRef = (*headRef)->next;
    free(temp);
    return item;
}

int main()
{
    struct stackNode *stackHead = NULL;

    int data;
    scanf("%d",&data);
    while(data > 0)
    {
        push(&stackHead,data);
        scanf("%d",&data);
    }

    printf("\n\nPopping...\n");
    while( !isEmpty(stackHead) )
    {
        printf("%d\n",pop(&stackHead));
    }
}
