#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;

int n, k, m;

int main()
{
	cin>>n>>m>>k;
	int a, b, w;

	vi fish (n+1, 0);
	for( int i = 1; i <= n; i++ )
	{
		cin>>a;
		while(a--)
		{
			cin>>b;
			--b;
			fish[i] |= 1<<b;
		}
	}

	vpii adj [n+1];
	for( int i = 0; i < m; i++ )
	{
		cin>>a>>b>>w;
		adj[a].pb(mp(b,w));
		adj[b].pb(mp(a,w));		
	}

	set < pair< int, pii > > s;

	int dist[n+1][1025], visited[n+1][1025];

	for( int i = 0; i <= n; i++ )
		for( int j = 0; j < 1024; j++ )
		{
			dist[i][j] = INT_MAX;
			visited[i][j] = 0;
		}


	dist[1][fish[1]] = 0;
	s.insert(mp(0, mp(1, fish[1]) ) );

	while( !s.empty() )
	{
		pair <int, pii> p = *s.begin();
		s.erase(s.begin());

		int cost = p.ff, u = p.ss.ff, fish_u = p.ss.ss; 
		if( visited[u][fish_u] == 1 )
			continue;

		visited[u][fish_u] = 1;

		for( int i = 0; i < adj[u].size(); i++ )
		{
			int v = adj[u][i].ff, v_cost = adj[u][i].ss;

			int final_fish = fish_u | fish[v];

			if( dist[v][final_fish] > dist[u][fish_u] + v_cost )
			{
				dist[v][final_fish] = dist[u][fish_u] + v_cost;
				s.insert( mp(dist[v][final_fish], mp(v,fish_u|fish[v])));
			}
		}
	}
	// for( int i = 1; i <= n; i++ )
	// {
	// 	for( int j = 0; j <= 31; j++ )
	// 	{
	// 		cout<<dist[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int mux= pow(2,k) - 1, min_cost = INT_MAX;
	for( int i = 0; i <= mux; i++ )
		for( int j = 0; j <= mux; j++ )
			if( (i | j) == mux )
				min_cost = min(min_cost, max(dist[n][i], dist[n][j]));

	cout<<min_cost<<endl;
}