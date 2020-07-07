#include<bits/stdc++.h>
using namespace std;

int mat[1000][1000];

int main()
{
    int t,n,e,i,j,u,v,c=0;
    scanf("%d",&t);
    scanf("%d",&n);
    if(t==1)
    {
        e = n-1;
    }
    else
        scanf("%d",&e);

    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        u = u-1;
        v = v-1;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    for(i=0; i<n; i++)
    {
        printf("Adjacency of %d: ",i+1);
        for(j=0; j<n; j++)
        {
            if(mat[i][j]==1)
                printf("%d ",j+1);
        }
        printf("\n");
    }
}
