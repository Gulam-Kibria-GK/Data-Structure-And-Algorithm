#include <cstdio>
#include <set>
#include <climits>
#include <utility>
#define sz 1009
#define pii pair<int,int>
#define mkp make_pair
using namespace std;

int rows,cols,t;
int dist[sz][sz];
int INF=INT_MAX;
int grid[sz][sz];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dijkstra()
{
    set<pair<int,pii>> Q;

    Q.insert({0,{1,1}});
    dist[1][1]=grid[1][1];

    while(!Q.empty())
    {
        pair<int,pii> pp=*(Q.begin());
        int ux=pp.second.first;
        int uy=pp.second.second;

        Q.erase(Q.begin());
        for(int i=0; i<4; i++)
        {
            int vx=ux+dx[i];
            int vy=uy+dy[i];

            if(vx<1 or vx>rows or vy<1 or vy>cols)
                continue;

            int w=grid[vx][vy];
            if(dist[vx][vy]>dist[ux][uy]+w)
            {
                dist[vx][vy]=dist[ux][uy]+w;
                Q.insert({dist[vx][vy],{vx,vy}});
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
        scanf("%d%d", &rows,&cols);

        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=cols; j++)
            {
                scanf("%d", &grid[i][j]);
                dist[i][j]=INF;
            }
        }

        dijkstra();
        printf("%d\n", dist[rows][cols]);
    }
}