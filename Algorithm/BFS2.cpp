#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[10000000],arr2[10000000];
set<ll>v[1000000];
ll n,m,a,b,f=1;

void bfs(){
    queue<ll>q;
    q.push(1);
    int i=0;
    while(q.size()){
        m=q.front();
        q.pop();
        while(v[m].size()){
            ++i;
            if(v[m].find(arr[i])==v[m].end()){f=0, cout<<"No"<<endl;return ;}
            v[m].erase(arr[i]);
            v[arr[i]].erase(m);
            q.push(arr[i]);
            f=1;
        }
    }
}
int main()
{
    ll i,j,k,l;
    cin>>n;
    for(i=0; i<n-1; i++)
    {
        cin>>k>>l;
        v[k].insert(l);
        v[l].insert(k);
    }
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]!=1){
        cout<<"No"<<endl;return 0;
    }
    bfs();
    if(f==1){
        cout<<"Yes"<<endl;
    }
}

