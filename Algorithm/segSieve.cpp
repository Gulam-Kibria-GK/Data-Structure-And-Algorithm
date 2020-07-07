#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define sz 32000
using namespace std;
 
bool pp[sz]; //initializes all false, means prime
vector<ll> vv;
 
void sieve() {
    bool pp[sz];
    for(ll i=0; i<=sz; i++) 
        pp[i]=true;
 
    for(int i=2; i*i<=sz; i++)
        if(pp[i])
            for(ll j=i*i; j<=sz; j+=i)
                pp[j] = false;
 
    for (ll i=2; i<sz; i++)
        if(pp[i]) 
            vv.push_back(i); 
}
void segSieve(ll l, ll r)
{ 
    ll seg=r-l+1;
    bool mark[seg+5];
    for(ll i=0; i<seg; i++)
        mark[i]=true;
    
        
    for(ll i=0; vv[i]*vv[i]<=r; i++)
    {
        ll cp=vv[i];
        ll base=(l/cp)*cp;
        if(base<l) 
            base+=cp;
 
        for(ll j=base; j<=r; j+=cp)
            mark[j-l]=false;
 
        if(base==cp) 
            mark[base-l]=true;
    }
 
    for(ll i=0; i<seg; i++)
        if(mark[i] && ((i+l)>1))
            printf("%lld\n", i+l);
    printf("\n");
}
 
int main()
{
    sieve(); 
    ll t,a,b;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &a,&b);
        segSieve(a,b); 
    } 
}