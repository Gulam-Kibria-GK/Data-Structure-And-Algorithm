#include<bits/stdc++.h>
using namespace std;
int linearsearch(int a[],int b,int x)
{
    int i;
    for(i=0; i<b; i++)
    {
        if(x==a[i])
        {
            return i;
        }
    }
    return -7;
}
int main()
{
    int ar[6]= {10,20,30,40,50,60};
    int a,b;
    cin>>a;
    b=sizeof(ar)/sizeof(ar[0]);
    b=linearsearch(ar,b,a);
    if(b>=0)
    {
        cout<<"The number ar["<<b<<"]="<<ar[b]<<" was found"<<endl;
    }
    else
        cout<<"The number "<<a<<" was not found"<<endl;
    return 0;
}
