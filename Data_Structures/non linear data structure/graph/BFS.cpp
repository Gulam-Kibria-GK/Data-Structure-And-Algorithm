#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool>visit;
vector< vector<int> >grp;
int level[100002],data[100006];
int par[1000];
int n;

void bfs(int s)
{
    int frnt,i,sz;
    queue<int>q;
    q.push(s);
    level[s] = 0;
    visit[s] = true;
    while(!q.empty())
    {
        frnt = q.front();
        q.pop();
        sz = grp[frnt].size();
        for(i=0; i<sz; i++)
        {
            if(!visit[grp[frnt][i]])
            {
                level[grp[frnt][i]] = level[frnt]+1;
                q.push(grp[frnt][i]);
                visit[grp[frnt][i]] = true;
                par[grp[frnt][i]] = frnt;
                cout<<grp[frnt][i]<<" ";
            }
        }
    }
}
void path(int s,int d)
{
    if(s==d)
    {
        cout<<s<<" ";
        return;
    }
    else
    {
        path(s,par[d]);

    }
    cout<<d<<" ";
}
int main()
{
    int e,u,v,i,j,t,x;
    scanf("%d%d",&n,&e);//input: 9 12
    visit.assign(10+2,false);
    memset(level,0,sizeof(level));
    grp.assign(10,vector<int>());
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        grp[u].push_back(v);
        /*
        8 1
        1 2
        2 5
        5 6
        6 3
        3 7
        6 7
        6 9
        9 7
        4 8
        4 5
        1 4
        */
        // grp[v].push_back(u);
    }
    int s,d;
    scanf("%d%d",&s,&d);//8 7
    bfs(s);
    x = d;
    //cout<<x<<" ";
    int c = 0;
    while(x!=s)
    {
        cout<<x<<" ";
        x = par[x];

    }
    cout<<x;
    //path(s,d);
}
