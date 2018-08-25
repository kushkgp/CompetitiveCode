#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

set <int> adj[200005];

int main()
{
	int n, m, a, b, t, head;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		for( int i = 0; i <= n; i++ )
			adj[i].clear();

		for( int i = 0; i < m; i++ )
		{
			cin>>a>>b;
			adj[a].insert(b);
			adj[b].insert(a);
		}

		cin>>head;
		set <int> undisc;
		queue <int> s;

		for( int i = 1; i <= n; i++ )
			if( i != head )
				undisc.insert(i);

		vector <int> level (n+1, INT_MAX);

		vector <bool> visited (n+1, false);

		s.push(head);
		level[head] = 0;
		visited[head] = true;

		while( !s.empty() )
		{
			int u = s.front();
			s.pop();
			for( auto it = undisc.begin(); it != undisc.end(); )
			{
				if( !visited[*it] && adj[u].find(*it) == adj[u].end() )
				{
					level[*it] = level[u] + 1;
					s.push(*it);
					visited[*it] = true;
					it = undisc.erase(it);
				}
				else
					++it;
			}
		}

		for( int i = 1; i <= n; i++ )
			if( i!=head )
				cout<<level[i]<<" ";
		cout<<endl;
	}
}