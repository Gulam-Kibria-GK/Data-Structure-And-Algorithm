#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mat[1000][1000];
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
                    mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }
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
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    for(i=0; i<e; i++)
    {
        cin>>u>>v>>c;
        mat[u][v] = 1;
    }
    floyedWorshel();
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
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

