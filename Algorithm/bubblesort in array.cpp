#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int c)
{
    int i,j;
    for(i=0;i<c-1;i++)
    {
        for(j=i;j<c-1-i;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}
void arraytraverse(int a[],int c)
{
    int i;
    for(i=0;i<c;i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int i,a[8]={5,4,98,22,33,56,493,90};
    int c=sizeof(a)/sizeof(a[i]);
    bubblesort(a,c);
    arraytraverse(a,c);
}
