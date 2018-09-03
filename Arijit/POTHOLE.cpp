#include <bits/stdc++.h>
using namespace std;

#define MAXVAL 100000005
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;
typedef long long int ll;

vi adj[205], ptr;
ll cap[205][205], flow[205][205];
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
	int T;
	cin>>T;
	while(T--)
	{
		int w;
		int a, b;
		cin>>n;
		for( int i = 0; i <= n; i++ )
			adj[i].clear();

		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));

		for( int i = 1; i <= n-1; i++ )
		{
			cin>>w;
			while(w--)
			{
				cin>>a;
				adj[i].pb(a);
				adj[a].pb(i);

				if( i == 1 || i == n || a == 1 || a == n  )
					cap[i][a] = 1;
				else
					cap[i][a] = MAXVAL;

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
}