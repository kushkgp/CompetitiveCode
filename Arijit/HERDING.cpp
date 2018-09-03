#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int m, n, k;

int visited[1005][1005];
char grid[1005][1005];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int cunt = 1, last = 1;

void dfs( int i, int j )
{
	if( visited[i][j] != -1 )
	{
		// cunt = visited[i][j];
		return;
	}
	
	visited[i][j] = last;
	int d;
	
	if( grid[i][j] == 'E' )
		d = 0;
	if( grid[i][j] == 'W' )
		d = 1;
	if( grid[i][j] == 'N' )
		d = 2;
	if( grid[i][j] == 'S' )
		d = 3;

	dfs( i + dx[d], j + dy[d] ); 
	// visited[i][j] = cunt;
}

int main()
{
	cin>>n>>m;
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			cin>>grid[i][j];

	memset( visited, -1, sizeof(visited) );

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			if( visited[i][j] == - 1 )
			{
				dfs( i, j );

				// if( cunt == last )
					last++;

				cunt++;
			}

	int u = 0;
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			u = max(u, visited[i][j]);

	for( int i = 1; i <= n; i++ )
	{
		for( int j = 1; j <= m; j++ )
			cout<<visited[i][j]<<" ";
		cout<<endl;
	}
	cout<<u<<endl;
}
