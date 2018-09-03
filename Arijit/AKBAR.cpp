#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector <int> vi;

vi adj[1000005];
int visited [1000005];
int level [1000005];
int N, R, M;

bool bfs( int s, int k )
{	
	queue <int> q;
	q.push(s);
	level[s] = 0;

	if( visited[s] == -1 )
		visited[s] = s;
	else
		return false;

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		if( level[v] == k )
			return true;

		for( int i = 0; i < adj[v].size(); i++ )
		{
			int u = adj[v][i];
			if( visited[u] == - 1 )
			{
				visited[u] = s;
				level[u] = level[v] + 1;
				q.push(u);
			}
			else
				if( visited[u] != s )
					return false;
		}
	}

	return true;
}
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int flag = 0;
		int N, R, M;
		cin>>N>>R>>M;

		for( int i = 0; i <= N; i++ )
		{
			level[i] = -1;
			visited[i] = -1;
			adj[i].clear();
		}

		int a, b;
		for( int i = 0; i < R; i++ )
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int i;
		for( i = 0; i < M; i++ )
		{
			cin>>a>>b;
			if( !bfs(a,b) )
			{
				flag = 1;
				cout<<"No"<<endl;
				break;
			}
		}

		if( flag == 1 )
			continue;
		
		for( int j = 1; j <= N; j++ )
			if( visited[j] == -1 )
			{	
				cout<<"No"<<endl;
				i = -1;
				break;
			}

		if( i == M )
			cout<<"Yes"<<endl;
	}
}