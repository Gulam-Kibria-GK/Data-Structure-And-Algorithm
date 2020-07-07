#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 999999
ll mat[1000][1000],next[1000][1000];
ll n,e;
void floyedWorshel()
{
    ll i,j,k;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(mat[i][j]>mat[i][k]+mat[k][j])
                {
                    mat[i][j] = mat[i][k]+mat[k][j];
                    next[i][j] = next[k][j];
                }
            }
        }
    }
}

void findPath(ll i,ll j)
{
    if(next[j][i]==j)
        return;
    findPath(i,next[j][i]);
    cout<<next[j][i]<<" ";
}

int main()
{
    ll i,j,k,u,v,c;
    cin>>n>>e;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i==j)
                mat[i][j] = 0;
            else
                mat[i][j] = INF;
        }
    }
    for(i=0; i<e; i++)
    {
        cin>>u>>v>>c;
        mat[u][v] = c;
        next[u][v] = u;
    }
    floyedWorshel();
    int s=1,d=3;
    cout<<s<<" ";
    findPath(1,3);
    cout<<d<<" ";
}
/*
4
6
4 3 8
3 2 5
4 1 2
2 1 2
1 2 3
2 3 2
*/
