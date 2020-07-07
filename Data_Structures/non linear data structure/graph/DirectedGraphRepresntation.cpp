
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e,i,j,u,v;
     freopen("input.txt","r",stdin);
    cin>>n>>e;
    vector<int>vt[100];
    for(i=0; i<e; i++)
    {
        cin>>u>>v;
        vt[u].push_back(v);
        // vt[v].push_back(u);when undirected graph

    }
    for(i=1; i<=n; i++)
    {
        int sz = vt[i].size();
        cout<<"For node "<<i<<": ";
        for(j=0; j<sz; j++)
        {
            cout<<vt[i][j]<<" ";
        }
        cout<<endl;
    }
}
