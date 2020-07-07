#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>v[1000000],v2;
ll in_deg[1000000];
ll vis[1000000];
void topological_sort(ll n)
{
    ll i,j,k,l,u,vn,siz;
    queue<ll>q;
    for(i=1; i<=n; i++)
    {
        if(in_deg[i]==0)
        {
            q.push(i);
            vis[i]=1;
        }
    }
    while(q.size())
    {
        u=q.front();
        q.pop();
        v2.push_back(u);
        siz=v[u].size();
        for(i=0; i<siz; i++)
        {
            vn=v[u][i];
            if(vis[vn]==0)
            {
                in_deg[vn]=in_deg[vn]-1;
                if(in_deg[vn]==0)
                {
                    q.push(vn);
                    vis[vn]=1;
                }
            }
        }
    }
}
int main()
{
    ll i,j,k,l,a,b,n,m;
    while(true)
    {
        cin>>n>>m;
        if(n==0 && m==0)return 0;
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        memset(in_deg,0,sizeof(in_deg));
        for(i=0; i<m; i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
        }
        for(i=1; i<=n; i++)
        {
            for(j=0; j<v[i].size(); j++)
            {
                in_deg[v[i][j]]=in_deg[v[i][j]]+1;
            }
        }
        topological_sort(n);
        for(i=0; i<v2.size(); i++)
        {
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        v2.clear();
    }
}
/*****************
7 7
4 1
4 5
4 6
1 2
2 3
5 3
6 7
****************/
