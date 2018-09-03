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
vector <bool> vis(MAXN);
int t = 0;
int cunt = 0;
vpi bridge;
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
			if( disc[u] < low[v])
			{
				bridge.pb(mp(min(u,v),max(u,v)));
				cunt++;
			}
		}
		else
			low[u] = min(low[u], disc[v]);
	}

	return;
}
int main()
{
	int T;
	cin>>T;
	int count = 1;
	while(T--)
	{
		int n, m, a, b;
		cin>>n>>m;
		cunt = 0;
		t = 0;
		cout<<"Caso #"<<count++<<endl;
		for( int i = 0; i <= n; i++ )
		{
			adj[i].clear();
			low[i] = INT_MAX;
			disc[i] = INT_MAX;
			vis[i] = false;
		}
		bridge.clear();
		for( int i = 0; i < m; i++ )
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for( int i = 1; i <= n; i++ )
			if( !vis[i] )
				dfs(i, -1);

		sort(bridge.begin(), bridge.end());
		if( bridge.size() == 0 )
			cout<<"Sin bloqueos"<<endl;
		else
		{
			cout<<bridge.size()<<endl;
			for( int i = 0; i < bridge.size(); i++ )
				cout<<bridge[i].ff<<" "<<bridge[i].ss<<endl;
		}
		
	}
}