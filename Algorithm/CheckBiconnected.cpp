#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define root -1

int parent[100005];
int low[100005];
int disc[100005];
bool visited[100005];
bool ap[100005];
int Time;
vector<int>vt[100005];
bool checkBiconnected(int u)
{
    int i;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++Time;

    int sz = vt[u].size();
    for(int i=0; i<sz; i++)
    {
        int v = vt[u][i];
        if(!visited[v])
        {
            children++;
            parent[v] = u;
            checkBiconnected(v);
            low[u] = min(low[u],low[v]);

            if(parent[u]==root && children>1)
            {
                ap[u] = true;
                return false;
            }
            if(parent[u]!=root && low[v]>=disc[u])
            {
                ap[u] = true;
                return false;
            }
        }
        else if(v!=parent[u])
            low[u] = min(low[u],disc[v]);
    }
    return true;
}

int main()
{
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0; i<n; i++)
    {
        parent[i] = root;
        visited[i] = false;
        ap[i] = false;
    }
    for(int i=0; i<e; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        vt[u].push_back(v); vt[v].push_back(u);
    }
    Time = 0;
    if(checkBiconnected(0))
    {
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
            {
                flag = false;
            }
        }
        if(flag)
            printf("The graph is a Biconnected.\n");
        else
            printf("The graph is NOT a Biconnected.\n");
    }
    else
        printf("The graph is NOT a Biconnected.\n");
}
