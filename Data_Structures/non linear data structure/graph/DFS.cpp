#include<bits/stdc++.h>
using namespace std;

int flag = 0;
int white = 0;
int grey = 1;
int black = -1;
int n,e;
int v=4;
int par[100003];
int status[100003];
vector<int>vt[100003];

void DFS(int s)
{
    status[s] = grey;
    int sz = vt[s].size();
    for(int i=0; i<sz; i++)
    {
        v = vt[s][i];
        if(grey==status[s] && status[v]==grey)
            flag = 1;
        if(status[v]==white)
        {
            par[v] = s;
            DFS(v);
        }
    }
    status[s] = black;
    //cout<<s<<" ";
}


int main()
{
    int i,j,u,s,d;
    memset(status,0,sizeof(status));
    scanf("%d%d",&n,&e);
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        vt[u].push_back(v);
        //vt[v].push_back(u);
    }
    flag = 0;

    //cout<<flag<<endl;


    for(i=1; i<=n; i++)
    {
        if(status[i]==white)
        {
            DFS(i);
            if(flag)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}

