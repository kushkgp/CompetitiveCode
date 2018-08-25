#include <bits/stdc++.h>
 
using namespace std;

vector <int> adj [100010]; 
int n,m;
int match[100010],level[100010];

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

int main()
{
    int e,x,y;
    cin>>n>>m>>e;

    while(e--)
    {
        cin>>x>>y;
        adj[x].push_back(n+y);
        adj[n+y].push_back(x);
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
    return 0;
}