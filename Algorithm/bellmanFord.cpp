//Make sure indexing NODES from 1
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#define sz 999
using namespace std;

vector< pair<int,int> > adj[sz];
bool negCycle;
int node,edge,x,y,c;
int dist[sz];
const int inf=99999;

void init()
{
    negCycle=false;
    for(int i=0; i<sz; i++)
        dist[i]=inf,adj[i].clear();
}

void bellmanFord(int src)
{
    dist[src]=0;

    for(int i=1; i<node; i++) //number of relaxation is 1 less |node|
    {
        for(int u=1; u<=node; u++) //taking node one by one
        {
            for(auto it: adj[u]) //find all of its adjacent node
            {
                int v=it.first;
                int w=it.second;
                int cost=dist[u]+w;
                dist[v]=min(dist[v],cost);
            }
        }
    }
}

bool detect_neg_cycle()
{
    for(int u=1; u<=node; u++)
    {
        for(auto it: adj[u])
        {
            int v=it.first;
            int w=it.second;
            int cost=dist[u]+w;

            if(dist[v]>cost) //still relaxing
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &node,&edge);
        init();

        while(edge--)
        {
            scanf("%d%d%d", &x,&y,&c);
            adj[x].push_back({y,c}); //directed
        }

        bellmanFord(1);

        //for(int i=1; i<=node; i++)
            //printf("%d --> %d\n", i,dist[i]);
        //printf("\n");

        if(detect_neg_cycle())
            printf("possible\n");
        else
            printf("not possible\n");
    }
}
