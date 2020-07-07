#include <bits/stdc++.h>
using namespace std;

int n,par[100],Rank[100];

void init(int n)
{
	for(int i=0; i<n; i++)
		par[i]=i,Rank[i]=0;
}

int Find(int x)
{
	if(x==par[x]) return x;
	return par[x]=Find(par[x]);
}

void Union(int x,int y)
{
	int px=Find(x),py=Find(y);

	if(px==py) return;

	if(Rank[px]<Rank[py])
		par[px]=py,Rank[py]++;

	else if(Rank[px]>Rank[py])
		par[py]=px,Rank[px]++;

	else 
	{
		par[py]=px;
		Rank[px]++;
	}
	///cout<<x<<"-->"<<Rank[px]<<", "<<y<<"-->"<<Rank[py]<<endl;
}

void print(int n)
{
	for(int i=1; i<=n; i++)
		cout<<"Node: "<<i<<", Parent: "<<par[i]<<", Rank: "<<Rank[i]<<endl;
}

int main()
{
	cin>>n;
	init(n);

	for(int i=0; i<3; i++)
	{
		int d,g;
		cin>>d>>g;
		Union(d,g);
	}

	print(n);
}