#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v[1000000];
ll dis[1000000];
ll mm[1000000];
ll n,m,a,b;

void bfs(ll ma){
    ll f,h,g=0;

    queue<ll>q;
    q.push(ma);
    dis[ma]=0;
    while(q.size()){
        f=q.front();
        q.pop();
        for(h=0;h<v[f].size();h++){
            if(mm[v[f][h]]==0){
                q.push(v[f][h]);
                dis[v[f][h]]=dis[f]+1;;
                mm[v[f][h]]=1;
            }
        }
    }
}

int main()
{
    ll i,j,k,l,t,ma;
    cin>>t;
    while(t--)
    {
        //ll ma=1000000;
        cin>>n>>m;
        for(i=0; i<m; i++){
            cin>>k>>l;
            //ma=min(ma,min(k,l));
            v[k].push_back(l);
            v[l].push_back(k);
        }
        cin>>ma;
        memset(dis,0,sizeof(dis));
        memset(mm,0,sizeof(mm));
        bfs(ma);
        for(i=1;i<n;i++){
            if(dis[i]){
                cout<<dis[i]*6<<" ";
            }
            else{
                cout<<-1<<endl;
            }
        }
        for(i=0;i<n;i++){
            v[i].clear();
        }
    }
}
