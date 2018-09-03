#include <bits/stdc++.h>

using namespace std;
int n, m, TIME;

#define ff first
#define ss second
pair <int, int> tr;
vector <pair<int,int> > start;

char adj[45][45];

long long int dp[45][45], instack[45][45];

long long int dfs( int i , int j, int pi, int pj )
{
	instack[i][j] = 1;

	if( adj[i][j] == 'x' )
	{
		instack[i][j] = 0;
		return dp[i][j] = 0;
	}
	
	if( adj[i][j] == '#' )
	{
		instack[i][j] = 0;
		return dp[i][j] = INT_MAX;
	}
	long long int tot = 0;
	if( adj[i][j] == 's' )
		tot = 1;

	long long int ans = INT_MAX;
	
	if( ( (i + 1) != pi || j != pj ) && (i + 1 < n) && instack[i+1][j] == 0 )
	{
		if( dp[i+1][j] == -1 )
			dp[i+1][j] = dfs( i+1, j, i, j );
		ans = min( ans, dp[i+1][j] ); 
	}

	if( ( (i - 1) != pi || j != pj ) && (i - 1 >= 0) && instack[i-1][j] == 0 )		
	{
		if( dp[i-1][j] == -1)
			dp[i-1][j] = dfs( i-1, j, i, j );
		ans = min( ans, dp[i-1][j]);
	}

	if( (i != pi || (j+1) != pj ) && ( j + 1 < m ) && instack[i][j+1] == 0  )
	{
		if( dp[i][j+1] == -1 )
			dp[i][j+1] = dfs( i, j+1, i, j );
		ans = min( ans, dp[i][j+1]);
	}

	if( ( i != pi || (j-1) != pj ) && ( j - 1 >= 0 ) && instack[i][j-1] == 0  )
	{
		if( dp[i][j-1] == -1 )
			dp[i][j-1] = dfs( i, j-1, i, j );
		ans = min( ans, dp[i][j-1]);
	}

	ans += tot;
	// cout<<ans<<" "<<i<<" "<<j<<endl;
	instack[i][j] = 0;
	return dp[i][j] = ans;
}
int main()
{
	cin>>n>>m>>TIME;
	memset(dp, -1, sizeof(dp));
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			cin>>adj[i][j];
			
			if( adj[i][j] == '@' )
				start.push_back( make_pair (i, j) );
		}
	}

	long long int x = INT_MAX;
	for( int i = 0; i < start.size(); i++ )
	{
		x = min(x, (long long int) dfs(start[i].ff, start[i].ss, -1, -1 ));
	}

	if( 2*x <= TIME )
		cout<<"SUCCESS"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
}