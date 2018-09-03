#include <bits/stdc++.h>
 
using namespace std;

#define pb push_back
vector <int> adj [1010]; 
int n, m, s, t;
int match[1010],level[1010];
vector <int> px, py, tx, ty;

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
			level[i] = INT_MAX;
	}
	level[0] = INT_MAX;

	while( !s.empty() )
	{
		int u = s.front();
		s.pop();

		if( u!= 0 )
		{
			for( int i = 0; i < adj[u].size(); i++ )
			{
				int v = adj[u][i];
				if( level[match[v]] == INT_MAX )
				{	
					level[match[v]] = level[u] + 1;
					s.push(match[v]);
				}
			}
		}	
	}

	return ( level[0] != INT_MAX );
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
		level[u] = INT_MAX;
		return false;
	}
	return true;
}

bool calc( int i , int j )
{
	int sum = abs( tx[j] - px[i] ) + abs( ty[j] - py[i] );

	if( sum*200 <= s*t )
		return true;
	else
		return false;
}
int main()
{
	int T, a, b;
	cin>>T;
	while(T--)
	{
		for( int i = 0; i < 1010; i++ )
			adj[i].clear();
		px.clear();
		py.clear();
		tx.clear();
		ty.clear();

	    int e,x,y;
	    cin>>n>>m>>s>>t;

	    for( int i = 0; i < n; i++ )
	    {
	    	cin>>a>>b;
	    	px.pb(a);
	    	py.pb(b);
	    }
	    
	   	for( int i = 0; i < m; i++ )
	    {
	    	cin>>a>>b;
	    	tx.pb(a);
	    	ty.pb(b);
	    }

	    for( int i = 0; i < n; i++ )
	    	for( int j = 0; j < m; j++ )
	    		if( calc(i,j) )
	    		{
	    			adj[i + 1].pb(n + j + 1);
	    			// cout<<i<<" "<<j<<endl;
	    		}

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