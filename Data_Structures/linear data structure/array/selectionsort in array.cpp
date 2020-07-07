#include<bits/stdc++.h>
using namespace std;
void swa(int *p,int *q);
void selection(int a[],int b)
{
    int i,j,min,in;
    for(i=0;i<b-1;i++)
    {
        min=a[i];
        in=i;
        for(j=i+1;j<b;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                in=j;
            }
        }
        swa(&a[i],&a[in]);
    }
}
void swa(int *p,int *q)
{
    int pot;
    pot=*p;
    *p=*q;
    *q=pot;
}
/*void ab(int a[],int o)
{
    int i;
     for(i=0;i<o;i++)
    {
        cout<<a[i]<<endl;
    }
}*/
int main()
{
    int i,n,a[]={10,870,90,66,50,60};
    n=sizeof(a)/sizeof(a[0]);
    selection(a,n);
    //ab(a,n);

     for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
