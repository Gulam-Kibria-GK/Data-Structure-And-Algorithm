#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
const ll mx_sz=2*(1e6+9);
vector< pair<ll,pair<ll,ll> > > pp;
ll par[mx_sz],mc,_rank[mx_sz];
 
ll Find_root(ll x)
{
    if(x==par[x]) return x;
    return x=Find_root(par[x]);
}
 
void Union(ll px,ll py)
{
    if(_rank[px]<_rank[py])
        swap(px,py);
 
    par[py]=px;
    _rank[px]+=_rank[py];
    _rank[py]=0;
}
 
void kruskal()
{
    for(ll i=0; i<pp.size(); i++)
    {
        ll w=pp[i].first;
        ll u=pp[i].second.first;
        ll v=pp[i].second.second;
 
        u=Find_root(u);
        v=Find_root(v);
 
        if(u!=v)
        {
            Union(u,v);
            //cout<<"for "<<u<<" and "<<v<<" w="<<w<<endl;
            mc+=w;
        }
    }
}
 
int main()
{
    ll n,m,k,x,y,z,root;
    cin>>n>>m;
 
    for(ll i=1; i<=n; i++)
        par[i]=i,_rank[i]=1;
 
    while(m--)
    {
        cin>>x>>y>>z;
        pp.push_back({z,{x,y}});
    }
    
    sort(pp.begin(),pp.end());
 
    mc=0,kruskal();
 
    cout<<mc<<endl;
}