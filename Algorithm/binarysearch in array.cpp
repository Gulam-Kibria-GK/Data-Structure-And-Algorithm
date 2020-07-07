#include<bits/stdc++.h>
using namespace std;
int binaryserch(int a[],int s,int it)
{
    int b=0;
    int e=s-1;
    int m;
    while(b<=e)
    {
        m=(b+e)/2;
        if(a[m]==it)
            return m;
        else if(a[m]<it)
            b=m+1;
        else
            e=m-1;
    }
    return -1;
}
int main()
{
    int i,a[10]= {1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(a)/sizeof(a[0]);
    int item;
    cin>>item;
    int loc=binaryserch(a,size,item);
    if(loc==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<loc<<endl;
    }
}
