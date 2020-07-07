#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector<ll>v[1000000];
ll vis[1000000];
ll dis[1000000];
ll c=0,hh;
void bfs(ll k)
{
    ll i,j,u,vn,siz,n,m;
    queue<ll>q;
    q.push(k);
    vis[k]=1;
    while(q.size())
    {
        u=q.front();
        q.pop();
        siz=v[u].size();
        ll szz;
        if(hh==u)
            szz=v[u].size();
        else
            szz=v[u].size()-1;
        for(i=0; i<siz; i++){
            vn=v[u][i];
            if(vis[vn]==0){
                if(szz<v[vn].size()-1)c++;
                vis[vn]=1;
                q.push(vn);
            }
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
        if(a!=b){
        v[a].pb(b);
        v[b].pb(a);
        }
    }
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            hh=i;
            bfs(i);
        }
    }
    cout<<c<<endl;
}

