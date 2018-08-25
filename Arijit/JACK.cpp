#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

vector <pii> adj[50005];

int main()
{
	int n, m, a, b, w;
	cin>>n>>m;

	for( int i = 0; i < m; i++ )
	{
		cin>>a>>b>>w;
		adj[a].push_back(mp(b,w));
		adj[b].push_back(mp(a,w));
	}

	vector <bool> visited (n+1, false);
	vector <int> d (n+1, INT_MAX);
	set <pii> s;
	s.insert(mp(0,1));
	d[1] = 0;

	while(!s.empty())
	{
		pii p = *s.begin();
		s.erase(s.begin());

		if( visited[p.ss] )
			continue;
		visited[p.ss] = true;
		int u = p.ss;

		for( int i = 0; i < adj[u].size(); i++ )
		{
			int v = adj[u][i].ff;
			if( d[v] > max(d[u], adj[u][i].ss) )
			{
				d[v] = max(d[u], adj[u][i].ss);
				s.insert(mp(d[v],v));
			}
		}

	}

	if( d[n] != INT_MAX )
		cout<<d[n]<<endl;
	else
		cout<<"NO PATH EXISTS"<<endl;
}