#include<bits/stdc++.h>
using namespace std;



/****************/

int arr[1000000];
void merge(int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if (L[i]<=R[j])arr[k]=L[i++];
        else{
            arr[k]=R[j++];
            //f+=(n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;k++;
    }
}
void mergeSort( int l, int r){
    if (l<r){
        int m = l+(r-l)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}

int main()
{
    int i,j,k,l,n,m,a,b;
    cin>>n;
    for(i=0; i<n; i++)cin>>arr[i];
    mergeSort(0, n-1);
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

/***************/


//hackerearth..........
/*
int A[1000000];
void merge(int start,int mid, int endd)
{
    int p = start,q = mid+1;
    int Arr[endd-start+1], k=0;

    for(int i = start ; i <= endd ; i++)
    {
        if(p > mid)Arr[ k++ ] = A[ q++] ;
        else if ( q > endd)Arr[ k++ ] = A[ p++ ];
        else if( A[ p ] < A[ q ])Arr[ k++ ] = A[ p++ ];
        else Arr[ k++ ] = A[ q++];
    }
    for (int p=0 ; p< k ; p ++)
    {
        A[ start++ ] = Arr[ p ] ;
    }
}

void merge_sort(int start, int endd)
{
    if( start < endd )
    {
        int mid = (start + endd ) / 2 ;
        merge_sort ( start, mid ) ;
        merge_sort (mid+1, endd ) ;
        merge(start, mid, endd );
    }
}
int main()
{
    int i,j,k,l,n,m,a,b;
    cin>>n;
    for(i=0; i<n; i++)cin>>A[i];
   merge_sort(0,n-1);
    for(i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
}
*/
