#include<bits/stdc++.h>
using namespace std;

#define root -1
int parent[100005];
int low[100005];
int disc[100005];
bool visited[100005];
bool ap[100005];
vector<int>adj[100005];
int Time;
// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void TarjanDFS(int u)
{
    int i;
    int children = 0;// Count of children in DFS Tree
    visited[u] = true;// Mark the current node as visited
    disc[u] = low[u] = ++Time;// Initialize discovery time and low value
    int  sz = adj[u].size();
    for (int i = 0; i<sz; ++i)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            TarjanDFS(v);
            // Check if the subtree rooted with v has a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);
            // u is an articulation point in following cases (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == root && children > 1)
                ap[u] = true;
            // (2) If u is not root and low value of one of its child is more than discovery value of u.
            if (parent[u] != root && low[v] >= disc[u])
                ap[u] = true;
        }
        else if(v != parent[u])// Update low value of u for parent function calls.
            low[u] = min(low[u], disc[v]);
    }
    cout<<endl<<endl;
    for(i=0; i<5; i++)
        cout<<low[i]<<" ";
    cout<<endl;
        for(i=0; i<5; i++)
        cout<<disc[i]<<" ";
    cout<<endl;
        for(i=0; i<5; i++)
        cout<<parent[i]<<" ";
    cout<<endl;
        for(i=0; i<5; i++)
        cout<<ap[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,e;
    cin>>n>>e;
    for (int i=0; i<n; i++)
    {
        parent[i] = root;
        visited[i] = false;
        ap[i] = false;
    }
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Time = 0;
    for (int i=0; i<n; i++)
        if (visited[i] == false)
            TarjanDFS(i);
    // Now ap[] contains articulation points, print them
    for (int i=0; i<n; i++)
        if (ap[i] == true)
            cout << i << " ";
    return 0;
}

