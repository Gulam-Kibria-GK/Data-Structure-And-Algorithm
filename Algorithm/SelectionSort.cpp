#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_idx])
            min_idx = j;
        }
        swap(arr[min_idx],arr[i]);
    }
}


int main()
{
    int i,j,k,l,n,m;
    cin>>n;
    int arr[n+5];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);
    for (i=0; i <n; i++)
        printf("%d ", arr[i]);
    return 0;
}
