#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (1<<30)
#define MAXN 55000

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

vpi adj[MAXN];
int ans;

int dfs( int i, int parent )
{
	int l1 = 0, l2 = 0;

	for( int j = 0; j < adj[i].size(); j++ )
	{
		if( adj[i][j].ff == parent )
			continue;
		l2 = max(l2, dfs( adj[i][j].ff , i ) + adj[i][j].ss );

		if( l2 > l1 )
			swap(l1, l2);
	}

	ans = max(ans, l1 + l2 );
	return l1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for( int i = 0; i <= n; i++ )
			adj[i].clear();

		int a, b, w;
		ans = 0;
		for( int i = 0; i < n - 1; i++ )
		{
			cin>>a>>b>>w;
			adj[a].pb(mp(b,w));
			adj[b].pb(mp(a,w));
		}
		dfs(1, -1 );
		cout<<ans<<endl;
	}
	return 0;
}