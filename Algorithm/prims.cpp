#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX=1e4+5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int src)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    long long minimumCost=0;
    PII p;
    Q.push(make_pair(0,src));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p=Q.top();
        Q.pop();
        u=p.second;
        // Checking for cycle
        if(marked[u])
            continue;

        minimumCost+=p.first;
        marked[x]=true;

        for(int v: adj[u])
        	if(not marked[v])
                Q.push(v);
    }
    return minimumCost;
}

int main()
{
    int nodes,edges,x,y,weight,minimumCost;
    cin>>nodes>>edges;

    for(int i=0; i<edges; i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));
    }
    // Selecting 1 as the starting node
    minimumCost=prim(1);
    cout<<minimumCost<<endl;
    return 0;
}