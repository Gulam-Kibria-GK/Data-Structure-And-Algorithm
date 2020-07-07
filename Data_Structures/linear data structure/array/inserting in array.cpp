#include<bits/stdc++.h>
using namespace std;
int ArrayInsertAtLoc(int a[],int max,int size,int item,int loc)
{
    if(size==max)
    {
        cout<<"array over flow can't insert."<<endl;
        return (size+1);
    }
    int i;
    for(i=size; i>=loc; i--)
        a[i+1]=a[i];
    a[loc]=item;
    size+=1;
    return (size+1);

}
void traverse(int a[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int a[6]= {10,20,30,40},i,loc,valu;
    int size=sizeof(a)/sizeof(a[0]);
    int size1=4;
    cin>>valu;
    cout<<"Enter the location: ";
    cin>>loc;
    size1=ArrayInsertAtLoc(a,size-1,size1-1,valu,loc-1);
    traverse(a,size1);
}
