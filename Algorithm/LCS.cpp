#include<bits/stdc++.h>
using namespace std;
#define ll long long
string st,st2;
ll L[10000][10000];

void LCS(ll n,ll m)
{
    ll i,j,k,a,b;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;
            }
            else if(st[i-1]==st2[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
}

int main()
{
    ll i,j,k,l,n,m;
    cin>>st>>st2;
    n=st.size();
    m=st2.size();
    // cout<<n<<m<<endl;
    LCS(n,m);
    cout<<L[n][m]<<endl;
}
