#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[100009],tree[900009];

void create_tree(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=arr[b];
       // cout<<tree[node]<<endl;
        return ;
    }
    ll mid=(b+e)/2;
    ll le=node*2;
    ll ra=node*2+1;
    create_tree(le,b,mid);
    create_tree(ra,mid+1,e);
    //tree[node]=tree[le]+tree[ra];
    tree[node]=min(tree[ra],tree[le]);
   // cout<<tree[node]<<endl;
}

void update(ll node,ll b,ll e,ll i,ll newvalue)
{
    if(i>e || i<b)return ;
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        return ;
    }
    ll mid=(b+e)/2;
    ll le=node*2;
    ll ra=node*2+1;
    update(le,b,mid,i,newvalue);
    update(ra,mid+1,e,i,newvalue);
    tree[node]=min(tree[le],tree[ra]);
}


ll query(ll node,ll b,ll e,ll i,ll j )
{
    if(i>e || j<b)
    {
        return INT_MAX;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll mid=(b+e)/2;
    ll le=node*2;
    ll ra=node*2+1;
    ll p=query(le,b,mid,i,j);
    ll p1=query(ra,mid+1,e,i,j);
    return min(p,p1);
}

int main()
{
    ll i,j,k,n,m,a,b,e,x,y,t;

    char ch;
    scanf("%lld %lld",&e,&m);
    for(i=1; i<=e; i++)
    {
        scanf("%lld",&arr[i]);
    }
    create_tree(1,1,e);
    while(m--)
    {
        cin>>ch>>x>>y;
        if(ch=='q')
        {
            ll ans=query(1,1,e,x,y);
            printf("%lld\n",ans);
        }
        else
        {
            update(1,1,e,x,y);
        }
    }
}

