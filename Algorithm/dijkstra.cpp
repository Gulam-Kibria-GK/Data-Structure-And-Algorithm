#include <cstdio>
#include <vector>
#include <climits>
#include <set>
#include <utility>
#define sz 100000
#define mp make_pair
using namespace std;

int n,e,x,y,c,t,tc=0;
int dist[sz];
vector< pair<int,int> > adj[sz];
int INF=INT_MAX;

void dijkstra(int src)
{
    //priority_queue< pii, vector< pii >, adjreater< pii > > Q;
    set< pair<int,int> > Q;

    Q.insert(mp(0, src));
    dist[src]=0;

    while(!Q.empty())
    {
        auto it=Q.begin();
        int u=it->second;

        Q.erase(Q.begin());

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].first;
            int w=adj[u][i].second;

            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                Q.insert(mp(dist[v],v));
            }
        }
    }
}

int main()
{
    //freopen("out.cpp", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        for(int i=0; i<=111; i++)
            adj[i].clear(),dist[i]=INF;

        scanf("%d%d", &n,&e);
        for(int i=0; i<e; i++)
        {
            scanf("%d%d%d", &x,&y,&c);
            adj[x].push_back({y,c});
            adj[y].push_back({x,c});
        }

        dijkstra(1); //source=1

        printf("Case %d: ", ++tc);

        if(dist[n]==INF) //destination=n
            printf("Not reached.\n");
        else
            printf("%d\n", dist[n]);
    }
}
