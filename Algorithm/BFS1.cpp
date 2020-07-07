#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a,b,c,d,n,m;
ll arr[10][10][10][10];

int dp1[8]= {1,2,1,2,-1,-2,-1,-2};
int dp2[8]= {2,1,-2,-1,2,1,-2,-1};

void bfs(ll a,ll b,ll c,ll d){
//    if(arr[a][b][c][d]!=-1)return arr[a][b][c][d];
//    if(arr[c][d][a][b]!=-1)return arr[c][d][a][b];

    ll x,y,k,l,r,s;
    ll vis[9][9]= {};
    queue<pair <ll,pair<ll,ll> > >q;
    pair< ll,pair<ll,ll> >temp;
    arr[a][b][a][b]=0;
    vis[a][b]=1;
    q.push({0,{a,b}});
    while(!q.empty())
    {
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
    //return arr[a][b][c][d];
}

int main()
{

    ll i,j,t;
    cin>>t;
    string st,st2;
    for(i=1; i<9; i++)
        for(j=1; j<9; j++)6
            for(int k=1; k<9; k++)
                for(int l=1; l<9; l++)
                    arr[i][j][k][l]=-1;
    while(t--)
    {
        cin>>st>>st2;
        a=st[0]-'a'+1;
        b=st[1]-'0';
        c=st2[0]-'a'+1;
        d=st2[1]-'0';
        if(arr[a][b][c][d]==-1)bfs(a,b,c,d);
        cout<<arr[a][b][c][d]<<endl;
    }
}

