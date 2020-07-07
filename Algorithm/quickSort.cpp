#include<bits/stdc++.h>
using namespace std;
int arr[10000];

//geeksforgeek........

/***********

int part(int arr[],int l,int h){
    int piovt=arr[h];
    int i=(l-1);
    for(int j=l;j<h-1;j++){
        if(arr[j]<=piovt){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}

void quickSort(int l,int h)
{
    if(l<h)
    {
        int j=part(l,h);
        quickSort(l,j-1);
        quickSort(j+1,h);
    }
}

int main()
{
    int i,j,k,l,n,m,a,b;
    cin>>n;
    for(i=0; i<n; i++)cin>>arr[i];
    //arr[n]=1000000;
    quickSort(0,n-1);
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}

*************/

//hackerearth..........

int part(int l,int h)
{
    int i,j;
    int pivot=arr[l];
    i=l;
    j=h;
    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i]<pivot);
        do
        {
            j--;
        }while(arr[j]>pivot);
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}




void quickSort(int l,int h)
{
    if(l<h)
    {
        int j=part(l,h);
        quickSort(l,j);
        quickSort(j+1,h);
    }
}

int main()
{
    int i,j,k,l,n,m,a,b;
    cin>>n;
    for(i=0; i<n; i++)cin>>arr[i];
    //arr[n]=1000000;
    quickSort(0,n);
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
