#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

vector <bool> sieve (2000000, true);
vector <bool> visited(100006);
vi id (100006);
vi adj [100005];
int cunt;

void dfs( int u )
{
	visited[u] = true;
	id[cunt]++;
	for( int i = 0; i < adj[u].size(); i++ )
		if( !visited[adj[u][i]])
			dfs(adj[u][i]);
}

int main()
{
	sieve[0] = sieve[1] = false;
	for( int i = 2; i < 2000000; i++ )
		if( sieve[i] )
			for( int j = 2; j*i < 2000000; j++ )
				sieve[j*i] = false;

	vi prime;
	for( int i = 2; i < 2000000; i++ )
		if( sieve[i])
			prime.pb(i);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, a, b;
		cin>>n>>m;
		cunt = 0;
		for( int i = 0; i <= n; i++ )
		{
			adj[i].clear();
			visited[i] = false;
			id[i] = 0;
		}

		for( int i = 0; i < m; i++ )
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		for( int i = 1; i <= n; i++ )
			if( !visited[i] )
			{
				cunt++;
				dfs(i);
			}

		int maxi = -1;
		for( int i = 1; i <= cunt; i++ )
			maxi = max(id[i], maxi);

		if( cunt == n || maxi == 1 )
			cout<<"-1"<<endl;
		else
			cout<<prime[maxi-1]<<endl;
	}
	return 0;
}