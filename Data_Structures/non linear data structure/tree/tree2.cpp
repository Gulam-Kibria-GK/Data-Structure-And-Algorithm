// Gach Traverse:
#include<stdio.h>
#include<stdlib.h>
struct gach
{
    struct gach *south;
    char *Mobin;
    struct gach *north;
};
struct gach *makenode(char *n)
{
    struct gach *p=(struct gach *)malloc(sizeof(struct gach));
    p->south=NULL;
    p->Mobin=n;
    p->north=NULL;
    return p;
}
void pr(struct gach *Palash)
{
    if(Palash==NULL)
    {
        return;
    }
    printf("%s\n",Palash->Mobin);
    pr(Palash->south);
    pr(Palash->north);
}
void i(struct gach *q)
{
    if(q==NULL)
    {
        return;
    }
    i(q->south);
    printf("%s\n",q->Mobin);
    i(q->north);
}
void pt(struct gach *r)
{
    if(r==NULL)
    {
        return;
    }
    pt(r->south);
    pt(r->north);
    printf("%s\n",r->Mobin);
}
int main()
{
    struct gach *Mango;
    char S1[10];
    scanf("%s",S1);
    Mango=makenode(S1);
    getchar();
    char S2[10];
    scanf("%s",S2);
    Mango->south=makenode(S2);
    getchar();
    char S3[10];
    scanf("%s",S3);
    Mango->north=makenode(S3);
    getchar();
    char S4[10];
    scanf("%s",S4);
    Mango->south->south =makenode(S4);
    getchar();
    char S5[10];
    scanf("%s",S5);
    Mango->south->north=makenode(S5);
    getchar();
    printf("\n#Preorder traverse:\n\n");
    pr(Mango);
    printf("\n#Inorder traverse:\n\n");
    i(Mango);
    printf("\n#Postorder traverse;\n\n");
    pt(Mango);
}
