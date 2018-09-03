#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector <int> vi;

vi adj[100005];
bool visited [100005];

void bfs(int s)
{	
	queue <int> q;
	q.push(s);

	visited[s] = true;

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for( int i = 0; i < adj[v].size(); i++ )
		{
			int u = adj[v][i];
			if( !visited[u] )
			{
				visited[u] = true;
				q.push(u);
			}				
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int flag = 0;
		int N, R, M;
		cin>>N>>M;

		for( int i = 0; i <= N; i++ )
		{
			visited[i] = false;
			adj[i].clear();
		}

		int a, b;
		for( int i = 0; i < M; i++ )
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int cunt = 0;
		for( int i = 0; i < N; i++ )
			if( !visited[i] )
			{
				cunt++;
				bfs(i);
			}
		cout<<cunt<<endl;
	}
}