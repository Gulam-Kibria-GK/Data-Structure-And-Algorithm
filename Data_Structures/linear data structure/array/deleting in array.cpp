#include<bits/stdc++.h>
using namespace std;
int arraydeleting(int a[],int s,int l)
{
    if(s==0)
    {
        cout<<"array underflow."<<endl;
        return s-1;
    }
    int i;
    for(i=l-1; i<s-1; i++)
        a[i]=a[i+1];
    return(s-1);
}
void traverse(int a[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int i,a[6]= {10,20,30,40,50,60};
    int size=6;
    int loc;
    cout<<"Enter the location to delete: ";
    cin>>loc;
    size=arraydeleting(a,size,loc);
    traverse(a,size);
}
