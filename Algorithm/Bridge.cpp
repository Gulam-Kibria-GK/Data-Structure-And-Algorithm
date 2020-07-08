#include<bits/stdc++.h>
using namespace std;

int low[10005];
int disc[10005];
int tim = 0;
vector<int>adj[100005];
int ans = 0;

struct db
{
    int x,y;
}ar[100005];

bool cmp(db aa,db bb)
{
    if(aa.x<bb.x)
        return true;
    if(aa.x==bb.x && aa.y<bb.y)
        return true;
    return false;

}


void TarjanDFS(int u,int fa)
{
    int i;
    disc[u] = low[u] = ++tim;
    int  sz = adj[u].size();
    for (int i = 0; i<sz; ++i)
    {
        int v = adj[u][i];
        if (!disc[v])//!disc[v]
        {
            TarjanDFS(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u] && v!=-1)
            {
                int a = min(u,v);
                int b = max(u,v);
                ar[ans].x = a;
                ar[ans].y = b;
                ans++;
                //cout<<a<<" "<<b<<endl;
            }
        }
        else if(v != fa)
            low[u] = min(low[u], disc[v]);
    }
}


int main()
{
    int t,i,j,n,e,u,v,m;
    scanf("%d",&t);
    while(scanf("%d",&n)==1)
    {

        ans = 0;
        for(j=0; j<=n; j++)
        {

            tim = 0;
            low[j] = 0;
            disc[j] = 0;
        }

        for(j=0; j<n; j++)
        {
            scanf("%d (%d)",&u,&m);
            for(int k=0; k<m; k++)
            {
                scanf("%d",&v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for (j=0; j<n; j++)
            if (!disc[j])
                TarjanDFS(j,-1);
        printf("Case %d:\n",i);

        printf("%d critical links\n",ans);
        sort(ar,ar+ans,cmp);
        for(j=0; j<ans; j++)
        {
            int a = ar[j].x;
            int b = ar[j].y;
            printf("%d - %d\n",a,b);
        }
        printf("\n");
        for(j=0; j<n; j++)
        {
            adj[j].clear();
        }
    }
}
