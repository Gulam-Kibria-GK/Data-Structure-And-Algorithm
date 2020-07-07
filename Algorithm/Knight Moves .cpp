#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll arr[10][10][10][10];
int dp1[8]= {1,2,1,2,-1,-2,-1,-2};
int dp2[8]= {2,1,-2,-1,2,1,-2,-1};

void bfs(ll a,ll b,ll c,ll d){
    ll x,y,k,l,r,s;
    ll vis[9][9]= {};
    queue<pair <ll,pair<ll,ll> > >q;
    pair< ll,pair<ll,ll> >temp;
    arr[a][b][a][b]=0;
    vis[a][b]=1;
    q.push({0,{a,b}});
    while(!q.empty()){
        temp=q.front();
        q.pop();
        x=temp.second.first;
        y=temp.second.second;
        l=temp.first;
        arr[a][b][x][y]=l;
        for(int i=0; i<8; i++){
            r=x+dp1[i];
            s=y+dp2[i];
            if(vis[r][s]!=1 && r>0 && s>0 && r<9 && s<9){
                vis[r][s]=1;
                q.push({l+1,{r,s}});

            }
        }
    }
}

int main()
{
    ll i,j,k,l,n,m,a,b,r,c,r1,c1;
    string st,st2;
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            for(k=0; k<9; k++)
                for(l=0; l<9; l++)
                    arr[i][j][k][l]=-1;

    while(cin>>st>>st2){
        r=st[0]-'a'+1;
        r1=st2[0]-'a'+1;
        c=st[1]-48;
        c1=st2[1]-48;
        if(arr[r][c][r1][c1]==-1)bfs(r,c,r1,c1);
        cout<<"To get from "<<st<<" to "<<st2<<" takes "<<arr[r][c][r1][c1]<<" knight moves."<<endl;
    }


}
