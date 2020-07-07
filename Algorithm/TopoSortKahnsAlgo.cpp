#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define sz 1000009
using namespace std;

int indegree[sz],n,m,x,y;
vector<int> adj[sz],st;

void topoSort()
{
	set<int> Q;
	int cnt=0;

	for(int i=1; i<=n; i++)
		if(indegree[i]==0)
			Q.insert(i);

	while(Q.size())
	{
		int u=*Q.begin();
		st.push_back(u);
		Q.erase(Q.begin());
		cnt++;

		for(int v: adj[u])
		{
			if(--indegree[v]==0)
				Q.insert(v);
		}
	}

	if(cnt!=n)
		printf("IMPOSSIBLE");
	else 
		for(int d=0; d<st.size(); d++) 
			printf("%d ", st[d]);
	printf("\n");

}

int main()
{
	while(scanf("%d%d", &n,&m))
	{
		if(n+m==0) break;

		st.clear();
		for(int i=0; i<sz; i++)
			adj[i].clear(),indegree[i]=0;

		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &x,&y);
			adj[x].push_back(y);
			indegree[y]++;
		}

		topoSort();
	}
}