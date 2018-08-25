#include <bits/stdc++.h>
using namespace std;

#define MAXVAL 1000000000000005
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;
typedef long long int ll;

vi adj[5005], ptr;
ll cap[5005][5005], flow[5005][5005];
int n, m;
vi level;

bool bfs()
{
	queue <int> s;
	s.push(1);	
	level.assign(n+1, -1);
	ptr.assign(n+1, 0);
	level[1] = 0;

	while(!s.empty())
	{
		int u = s.front();
		s.pop();
		for( int i = 0; i < adj[u].size(); i++ )
		{
			int v = adj[u][i];
			if( level[v] == -1 && cap[u][v] > flow[u][v] )
			{
				level[v] = level[u] + 1;
				s.push(v);
			}
		}
	}
	return ( level[n] != -1 );
}

ll dfs( int u, ll fl )
{
	if( u == n )
		return fl;

	for( ; ptr[u] < adj[u].size(); ++ptr[u] )
	{
		int v = adj[u][ptr[u]];
		if( level[v] == level[u] + 1 && cap[u][v] > flow[u][v] )
		{
			ll newflow = min(fl, (long long int )cap[u][v] - flow[u][v]);
			newflow = dfs( v, newflow );
			if( newflow > 0 )
			{
				flow[u][v] += newflow;
				flow[v][u] -= newflow;
				return newflow;
			}
		}
	}
	return 0;
}

int main()
{
	int a, b, w;
	cin>>n>>m;
	memset(flow, 0, sizeof(flow));
	for( int i = 0; i < m; i++ )
	{
		cin>>a>>b>>w;
		if(cap[a][b])
		{
			cap[a][b] += w;
			cap[b][a] += w;
		}
		else
		{
			adj[a].pb(b);
			adj[b].pb(a);
			cap[a][b] += w;
			cap[b][a] += w;
		}
	}

	long long int ans = 0;
	while(bfs())
	{
		while(1)
		{
			ll d = dfs(1, MAXVAL);
			if( d == 0 )
				break;
			ans += d;
		}
	}
	cout<<ans<<endl;
}