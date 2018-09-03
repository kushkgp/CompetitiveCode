#include <bits/stdc++.h>
 
using namespace std;

#define INF 10000000000005
#define pb push_back
vector <int> adj [2010]; 
int n, m, s, t;
long long int match[2010],level[2010];
vector <int> fl;

long long int dist[505][505];

bool bfs()
{
	queue <int> s;

	for( int i = 1; i <= n; i++ )
	{
		if( match[i] == 0 )
		{
			level[i] = 0;
			s.push(i);
		}
		else
			level[i] = INF;
	}
	level[0] = INF;

	while( !s.empty() )
	{
		int u = s.front();
		s.pop();

		if( u!= 0 )
		{
			for( int i = 0; i < adj[u].size(); i++ )
			{
				int v = adj[u][i];
				if( level[match[v]] == INF )
				{	
					level[match[v]] = level[u] + 1;
					s.push(match[v]);
				}
			}
		}	
	}

	return ( level[0] != INF );
} 

bool dfs( int u )
{
	if( u!= 0 )
	{
		for( int i = 0; i < adj[u].size(); i++ )
		{
			int v = adj[u][i];
			if( level[u] + 1 == level[match[v]] && dfs(match[v]) )
			{
				match[u] = v;
				match[v] = u;
				return true;
			}
		}
		level[u] = INF;
		return false;
	}
	return true;
}

int main()
{
	long long T, a, b, w;
	cin>>T;
	while(T--)
	{
		for( int i = 0; i < 1010; i++ )
			adj[i].clear();

		fl.clear();

		cin>>n>>m>>s>>t;
		for( int i = 0; i < s; i++ )
		{
			cin>>a;
			fl.pb(a);
	    }

		for( int i = 1; i <= n; i++ )
			for( int j = 1; j <= n; j++ )
				dist[i][j] = INF;

	    for( int i = 1; i <= n; i++ )
	    	dist[i][i] = 0;

	    for( int i = 0; i < m ; i++ )
	    {
	    	cin>>a>>b>>w;
	    	dist[a][b] = min(dist[a][b], w);
	    	dist[b][a] = min(dist[b][a], w);
	    }

	    for( int k = 1; k <= n ; k++ )
	    	for( int i = 1; i <= n; i++ )
	    		for( int j = 1; j <= n; j++ )
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		for( int i = 0; i < s; i++ )
			for( int j = 1; j <= n; j++ )
				if(dist[fl[i]][j] <= t)
					adj[i+1].pb( s + j );
		
		m = n;
		n = s;
	    memset(match, 0, sizeof(match));
	    long long int ans = 0;
	    while( bfs() )
	    {
	    	for( int i = 1; i <= n; i++ )
	    		if( match[i] == 0 && dfs(i) )
	    			ans++;
	    }
	    cout<<ans<<endl;
	}
    return 0;
}