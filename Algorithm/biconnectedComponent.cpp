#include<bits/stdc++.h>
using namespace std;
#define root -1
#define N 100005

int parent[N],disc[N],low[N],Time;
bool visited[N],ap[N];
vector<int>vt[N];
stack<int>st;

void biconnectedComponent(int u)
{
    int i,sz,v,x,y,children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++Time;
    sz = vt[u].size();
    for(i=0; i<sz; i++)
    {
        v = vt[u][i];
        if(!visited[v])
        {
            children++;
            parent[v] = u;
            st.push(u); st.push(v);
            biconnectedComponent(v);
            low[u] = min(low[u],low[v]);
            if(parent[u]==root && children>1)
            {
                map<int,int>mp;
                while(st.top()!=v)
                {
                    x = st.top(); st.pop();
                    y = st.top(); st.pop();
                    mp[x] = x;
                    mp[y] = y;
                    //cout<<x<<" "<<y<<endl;
                }
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                cout<<x<<" "<<y<<endl<<endl;
            }
            if(parent[u]!=root && low[v]>=disc[u])
            {
                while(st.top()!=v)
                {
                    x = st.top(); st.pop();
                    y = st.top(); st.pop();
                    cout<<x<<" "<<y<<endl;
                }
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                cout<<x<<" "<<y<<endl<<endl;
            }
        }
        else if(v!=parent[u] && disc[v]<low[u])
        {
            low[u] = disc[v]; st.push(u); st.push(v);
        }
    }
}

int main()
{
    int n,e,i,j,u,v,x,y;
    scanf("%d%d",&n,&e);
    for(i=0; i<=n; i++)
    {
        parent[i] = root; visited[i] = ap[i] = false;
    }
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    cout<<endl<<endl;
    Time = 0;
    for(i=0; i<n; i++)
    {
        if(!visited[i])
        {
            biconnectedComponent(i);
            while(!st.empty())
            {
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                cout<<x<<" "<<y<<endl;
            }
            cout<<endl;
        }
    }
}
