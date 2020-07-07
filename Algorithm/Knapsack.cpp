#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>pr,we,v3;
ll gr[1000][1000];
Knapsack(ll n,ll m)
{
    ll i,j,k,l,a,b;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                gr[i][j]=0;
            }
            else if(we[i-1]<=j){
                gr[i][j]=max(pr[i-1]+gr[i-1][j-we[i-1]],gr[i-1][j]);
            }
            else{
                gr[i][j]=gr[i-1][j];
            }
        }
    }

}


int main()
{
    ll i,j,k,n,m,a;
    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        cin>>a;
        pr.push_back(a);
    }
    for(i=0; i<n; i++)
    {
        cin>>a;
        we.push_back(a);
    }
    Knapsack(n,m);
    cout<<gr[n][m]<<endl;
}
