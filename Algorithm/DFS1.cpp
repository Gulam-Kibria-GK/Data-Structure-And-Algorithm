#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector<char>v[100000];
//ll v[1000][1000];

ll a,b,c=0;
void dfs(ll x,ll y){
    if(x<0 || y<0 || x>=b || y>=a)return;
    if(v[x][y]=='#')return;
    v[x][y]='#';
    c++;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);

}

int main()
{
    ll i,j,k,l,t,n,m,x,y;
    char ch;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a>>b;
        for(j=0;j<b;j++){
            for(k=0;k<a;k++){
                cin>>ch;
                v[j].pb(ch);
                if(ch=='@'){
                    x=j;
                    y=k;
                }
            }
        }
        dfs(x,y);
        memset(v,0,sizeof(v));
        cout<<"Case "<<i<<": "<<c<<endl;
        c=0;
    }
}
