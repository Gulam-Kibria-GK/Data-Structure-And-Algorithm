#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct data
{
    ll n,c;
    data()
    {
    }

    data(ll n1,ll c1)
    {
        n=n1;
        c=c1;
    }
};
vector<data>v[1000000];

int main()
{
    ll i,j,k,l,n,m,a,b,c,e,mi=1<<28;
    //cout<<mi<<endl;
    freopen("input.txt","r",stdin);
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        cin>>a>>b>>c;
        mi=min(mi,c);
        v[a].push_back(data(b,c));
        v[b].push_back(data(a,c));
    }
    cout<<mi<<endl;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<v[i].size(); j++)
        {
            if(v[i][j].c==mi)
            {
                cout<<i<<" "<<v[i][j].n<<endl;
            }
        }
    }
}

