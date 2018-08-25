#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

vector <int> adj[200005];
vector <int> qcount;
vector <bool> visited (200005);
unordered_map <int, unordered_set<int> > queries ;
int initial;
void dfs( int vertex )
{
	visited[vertex] = true;
	// printf("VER");
	for( int i = 0; i < adj[vertex].size(); i++ )
	{
		int v = adj[vertex][i];
		if( !visited[v] )
		{
			qcount[v] = qcount[vertex];

			if( queries.find(vertex) != queries.end() )
				if( queries[vertex].find(v) != queries[vertex].end() )
				{
					qcount[v]++;
					initial++;
				}

			if( queries.find(v) != queries.end() )
				if( queries[v].find(vertex) != queries[v].end() )
					qcount[v]--;
			
			dfs(v);
		}
	}
}

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main()
{
	int n, m, a, b, t, head;
	cin>>t;
	while(t--)
	{
		cin>>n;

		for( int i = 0; i <= n; i++ )
		{
			adj[i].clear();
			visited[i] = false;
			initial = 0;
		}

		queries.clear();

		for( int i = 0; i < n-1; i++ )
		{
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		qcount.assign(n+1, -1);
		int q, k;
		
		cin>>q>>k;

		for( int i = 0; i < q; i++ )
		{
			scanf("%d%d",&a,&b);
			queries[a].insert(b);
		}

		qcount[1] = 0;

		for( int i = 1; i <= n; i++ )
			if( !visited[i] )
				dfs(i);

		int ans = 0;
		for( int i = 1; i <= n; i++ )
			if( initial - qcount[i] >= k )
				ans++;

		if( ans != 0 )
			cout<<ans/gcd(ans,n)<<"/"<<n/gcd(ans,n)<<endl;
		else
			cout<<"0/1"<<endl;

	}



}