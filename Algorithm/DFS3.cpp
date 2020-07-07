#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector<ll>v[1000000];
ll vis[1000000];
ll hh=0,c=0;
void dfs(ll s)
{
    vis[s]=1;
    for(ll i=0; i<v[s].size(); i++){
        c++;
        if(vis[v[s][i]]==0){
            dfs(v[s][i]);
        }
    }
}
int main()
{
    ll i,j,k,l,n,m,a,b,f=0;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
    }
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            hh=max(c/2,hh);
            c=0;
        }
    }
    cout<<hh<<endl;
}


