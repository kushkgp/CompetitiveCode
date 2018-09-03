#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int m, n, k;

int visited[55][55];
char lake[55][55];

int dx [4] = { 1, -1, 0, 0 };
int dy [4] = { 0, 0, 1, -1 };

void dfs( int i , int j, int& count )
{
	if( i < 1 || j < 1 || i > n || j > m )
		return;

	if( lake[i][j] != '.' )
		return;

	visited[i][j] = count;

	for( int d = 0; d < 4; d++ )
		if( visited[i+dx[d]][j+dy[d]] == - 1 )
			dfs(i + dx[d], j + dy[d], count );
	return;
}

int main()
{
	cin>>n>>m>>k;
	char a;

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			cin>>lake[i][j];

	memset( visited, -1, sizeof(visited) );
	int count = 1;

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			if( visited[i][j] == -1 && lake[i][j] == '.' )
			{	
				dfs(i,j,count);
				count++;
			}

	vector < pair<int, int> > vec [count + 1];
	count--;

	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			if( visited[i][j] != - 1 )
				vec[visited[i][j]].pb(mp(i,j));


	set <pair<int, int> > MAXD;
	set <int> OCEAN;

	for( int i = 1; i <= n; i++ )
	{
		if( visited[i][m] != -1 )
			OCEAN.insert(visited[i][m]);
		if( visited[i][1] != -1 )
			OCEAN.insert(visited[i][1]);
	}

	for( int i = 1; i <= m; i++ )
	{
		if( visited[1][i] != -1 )
			OCEAN.insert(visited[1][i]);
		if( visited[n][i] != -1 )
			OCEAN.insert(visited[n][i]);

	}

	for( int i = 1; i <= count; i++ )
		MAXD.insert(mp(vec[i].size(),i));

	int temp = 0, ans = 0, index;

	count -= OCEAN.size();
	for( auto it = MAXD.begin(); it != MAXD.end(); it++ )
	{
		if( count <= k )
			break;

		index = (*it).ss;

		if( OCEAN.find(index) != OCEAN.end() )
			continue;

		ans += (*it).ff;

		for( int i = 0; i < vec[index].size(); i++ )
			lake[vec[index][i].ff][vec[index][i].ss] = '*';

		count--;
	}

	cout<<ans<<endl;
	for( int i = 1; i <= n; i++ )
	{
		for(int j = 1; j <= m; j++ )
			cout<<lake[i][j];
		cout<<endl;
	}
	return 0;

}
