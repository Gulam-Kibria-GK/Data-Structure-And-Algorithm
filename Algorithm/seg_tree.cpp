#include <stdio.h>
#include <algorithm>
#define mx 100009
#define in(x) scanf("%d", &x)
using namespace std;
int arr[mx],cnt=0;
int tree[mx*4],x;

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int l=node*2;
    int r=node*2+1; 
    int m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e or j<b)
        return 0;
    if(b>=i and e<=j)
        return tree[node];

    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    int p1=query(l,b,m,i,j);
    int p2=query(r,m+1,e,i,j);
    return (p1+p2);
}

void update(int node,int b,int e,int i,int val)
{
    if(i>e or i<b)
        return;

    if(b>=i and e<=i)
    {
        if(x==1) tree[node]=0;
        else tree[node]+=val;
        return;
    }

    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    update(l,b,m,i,val);
    update(r,m+1,e,i,val);
    tree[node]=tree[l]+tree[r];
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);

    int t,tc=0,n,q;
    in(t);
    while(t--)
    {
        in(n);
        for(int i=1; i<=n; i++)
            in(arr[i]);
        init(1,1,n);

        for(int i=1; i<=n; i++)
        {
            int beg=i-arr[i];
            int end=i+arr[i];

            if(beg<1) beg=1;
            if(end>n) end=1;
            update()
        }

    }
    return 0;
}