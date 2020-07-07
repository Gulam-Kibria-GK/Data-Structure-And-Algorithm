#include<bits/stdc++.h>
using namespace std;
#define ll long long
string st,st2,st3;
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

    ll x,y;
    x=n;y=m;
    while(x>0 && y>0){
        if(st[x-1]==st2[y-1]){
            st3.push_back(st[x-1]);
            x--,y--;
        }
        else if(L[x-1][y]>=L[x][y-1]){
            x--;
        }
        else y--;
    }
    reverse(st3.begin(),st3.end());
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
    cout<<st3<<endl;
}

/***********
AGGTAB
GXTXAYB
***********/
