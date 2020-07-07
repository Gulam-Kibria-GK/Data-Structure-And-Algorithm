#include<bits/stdc++.h>
using namespace std;
#define ll long long
void insertionSort(ll arr[],ll n,ll f)
{
    ll i,j,k,kk=0;
    for(i=1; i<n; i++)
    {
        k=arr[i];
        for(j=i-1; j>=0; j--)
        {
            if(k<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }

        }
        arr[j+1]=k;
        for(ll kk=0; kk<n; kk++)
        {
            cout<<arr[kk]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ll i,j,k,l,n,m,a,b;
    cin>>n;
    ll f=0;
    ll arr[n+5];
    for(i=0; i<n; i++)cin>>arr[i];
    insertionSort(arr,n,f);
}
