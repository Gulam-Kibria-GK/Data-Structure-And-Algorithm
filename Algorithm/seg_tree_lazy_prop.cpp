#include <cstdio>
#include <algorithm>
#define ll long long
#define sz 100009
using namespace std;
ll n,u,arr[sz],tc=0;

struct info 
{
    ll prop,sum;
} tree[4*sz];

void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].sum=0;
        return;
    }
    ll l=node*2;
    ll r=node*2+1;
    ll m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[node].sum=tree[l].sum+tree[r].sum;
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e or j<b)
        return;
    if(b>=i and e<=j)
    {
        tree[node].sum+=((e-b+1)*x); 
        tree[node].prop+=x;
        return;
    }
    ll l=node*2;
    ll r=(node*2)+1;
    ll m=(b+e)/2;
    update(l,b,m,i,j,x);
    update(r,m+1,e,i,j,x);
    tree[node].sum=tree[l].sum+tree[r].sum+(e-b+1)*tree[node].prop;
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(i>e or j<b)
        return 0;
    if(b>=i and e<=j)
        return tree[node].sum+carry*(e-b+1); 

    ll l=node*2;
    ll r=node*2+1;
    ll m=(b+e)/2;

    ll p1=query(l,b,m,i,j,carry+tree[node].prop);
    ll p2=query(r,m+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}

void trav(ll node,ll b,ll e)
{
    printf("%lld ", tree[node].sum);
    ll l=node*2,r=node*2+1,m=(l+r)/2;

    trav(node,l,m);
    trav(node,m+1,r);
}

int main()
{
	for(ll i=0; i<=4*sz; i++)
		tree[i].sum=0,tree[i].prop=0;

    scanf("%lld%lld", &n,&u);
    init(1,1,n);

    ll xx,yy,i,j;
    while(u--)
    {
        ll cc=0;
        scanf("%lld%lld", &xx,&yy);
        //if(xx>yy) swap(xx,yy);

        ll beg=xx*cc+yy,end=beg;
        if(beg>n) continue;
        while(true)
        {
            ll ff=xx*(++cc)+yy;
            if(ff>n) break;
            end=ff;
        }
        i=beg,j=end;
        printf("a = %lld, b = %lld\n", i,j);
        update(1,1,n,i,j,1);
        printf("After %lld: ", ++tc);
        for(i=1; i<=n; i++)
        printf("%lld ", query(1,1,n,i,i,0));
    printf("\n");
    }

}