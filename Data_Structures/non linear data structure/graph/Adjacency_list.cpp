#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e,i,j,k,u,v,t;

    scanf("%d",&t);
    scanf("%d",&n);

    vector<int>mat[n];
    if(t==1)
    {
        e = n-1;
    }
    else
        scanf("%d",&e);
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        mat[u].push_back(v);
        mat[v].push_back(u);
    }
    int siz;
    for(i=1; i<=n; i++)
    {
        siz = mat[i].size();

        printf("Adjacent of %d: ",i);
        for(j=0; j<siz; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }


}

