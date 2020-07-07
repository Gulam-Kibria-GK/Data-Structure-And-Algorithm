#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>v[1000000];
ll satus[100000];
ll wh=0,gr=1,bl=-1;
ll star[100000];
ll endd[100000];
ll tim=0;
stack<ll>st;
void dfs(ll s)
{
    ll i,j,k,u,vn,siz;
    satus[s]=gr;
    tim=tim+1;
    star[tim]=s;
    siz=v[s].size();
    for(i=0; i<siz; i++){
        vn=v[s][i];
        if(satus[vn]==gr){
            cout<<"Sandro fails."<<endl;
            exit(0);
        }
        if(satus[vn]==wh){
            dfs(vn);
        }
    }
    tim=tim+1;
    st.push(s);
    satus[s]=bl;
}
int main()
{
    ll i,j,k,l,n,m,a,b;
    cin>>n>>m;
    for(i=0; i<m; i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(i=1;i<=n;i++){
        sort(v[i].rbegin(),v[i].rend());
    }
    for(i=n;i>0;i--){
        if(satus[i]==wh){
            dfs(i);
        }
    }
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();    }
    cout<<endl;
}
