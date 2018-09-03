#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAXN 10005

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

vi adj [MAXN];
vi low (MAXN);
vi disc (MAXN);
vector <bool> ap (MAXN);
vector <bool> vis(MAXN);
int t = 0;
int cunt = 0;

void dfs( int u, int parent )
{
	disc[u] = low[u] = t++;
	vis[u] = true;
	int rcunt = 0;
	for( int i = 0; i < adj[u].size(); i++ )
	{
		int v = adj[u][i];
		if( v == parent )
			continue;

		if( !vis[v] )
		{
			rcunt++;
			dfs(v,u);
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], disc[v]);

		if( disc[u] <= low[v] && parent != -1 )
			ap[u] = true;
	}

	if( parent == -1 && rcunt > 1 )
		ap[u] = true;

	return;
}
int main()
{
	while(1)
	{
		int n, m, a, b;
		cin>>n>>m;
		if( !n && !m )
			return 0;
		cunt = 0;
		t = 0;

		for( int i = 0; i <= n; i++ )
		{
			adj[i].clear();
			low[i] = INT_MAX;
			disc[i] = INT_MAX;
			ap[i] = false;
			vis[i] = false;
		}
		for( int i = 0; i < m; i++ )
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for( int i = 1; i <= n; i++ )
			if( !vis[i] )
				dfs(i, -1);

		for( int i = 1; i <= n; i++ )
			if( ap[i] )
				cunt++;

		cout<<cunt<<endl;
	}

	return 0;
}