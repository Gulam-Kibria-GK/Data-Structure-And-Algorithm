#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,a[5];
   // populate an array
   for(i=0;i<5;i++)
       cin>>a[i];
   // traversing while loop
   i=0;
   while(i<5)
   {
       a[i]=a[i]*4;
       i++;
   }
   // traversing using or loop
   for(i=0;i<5;i++)
       cout<<a[i]<<endl;
    return 0;
}
