#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

string m, n, k;

int visited[9][9];
char grid[9][9];

int dx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
int dy[8] = {2, -2, 2, -2, 1, 1, -1, -1};

int cunt = 1, last = 1;

int bfs( int i, int j, int a, int b )
{
	queue <pair<int,int> > q;

	q.push(mp(i,j));
	visited[i][j] = 0;

	while(!q.empty() )
	{
		pair <int, int> p = q.front();
		q.pop();

		for( int k = 0; k < 8; k++ )
		{
			int x = p.ff + dx[k], y = p.ss + dy[k];
			if( x >= 1 && x<= 8 && y >= 1 && y <= 8 && visited[x][y] == -1 )
			{
				visited[x][y] = visited[p.ff][p.ss] + 1;
				q.push(mp(x,y));
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
		cin>>n>>m;
	
		memset( visited, -1, sizeof(visited) );

		int i = n[0] - 'a' + 1, j = n[1] - '0';
		int a = m[0] - 'a' + 1, b = m[1] - '0';
		bfs(i,j,a,b);

		cout<<visited[a][b]<<endl;
	}
}
