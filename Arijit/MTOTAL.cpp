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
	s.push(27);	
	level.assign(n+1, -1);
	ptr.assign(n+1, 0);
	level[27] = 0;

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
	int w;
	char a, b;
	n = 52;
	cin>>m;
	memset(flow, 0, sizeof(flow));
	for( int i = 0; i < m; i++ )
	{
		cin>>a>>b>>w;

		int k, l;
		if( a >= 'a' && a <= 'z' )
			k = a - 'a' + 1;
		else
			k = a - 'A' + 27;

		if( b >= 'a' && b <= 'z' )
			l  = b - 'a' + 1;
		else
			l = b - 'A' + 27;
		
		if(cap[k][l])
		{
			cap[k][l] += w;
			cap[l][k] += w;
		}
		else
		{
			adj[k].pb(l);
			adj[l].pb(k);
			cap[k][l] += w;
			cap[l][k] += w;
		}
	}

	long long int ans = 0;
	while(bfs())
	{
		while(1)
		{
			ll d = dfs(27, MAXVAL);
			if( d == 0 )
				break;
			ans += d;
		}
	}
	cout<<ans<<endl;
}