#include <bits/stdc++.h>

using namespace std;

int dp[21][1005][2], batch[21], cost[25][25], rating[25][25];
int n, m, k;
		
int recur( int bat, int k, int seal)
{
	if( bat == n || k <= 0 )
		return 0;

	if( dp[bat][k][seal]!= -1 )
		return dp[bat][k][seal];

	int temp1 = recur( bat+1, k, 0);
	int ans = 0;
	if(seal)
	{
		for( int i = 0; i < m; i++ )
			if( cost[bat][i] <= k )
				ans = max(ans, rating[bat][i] + recur(bat,k - cost[bat][i],1));
	}
	else
	{
		int rem = k - batch[bat];
		for( int i = 0; i < m; i++ )
		if( cost[bat][i] <= rem )
			ans = max(ans, rating[bat][i] + recur(bat,rem - cost[bat][i],1));
	}

	dp[bat][k][seal] = max(ans,temp1);
	return max(ans,temp1);
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>m>>k;

		memset(dp, -1, sizeof(dp));
		for( int i = 0; i < n; i++)
			cin>>batch[i];			

		for( int i = 0; i < n; i++)
			for( int j = 0; j < m; j++)
				cin>>cost[i][j];

		for( int i = 0; i < n; i++)
			for( int j = 0; j < m; j++)
				cin>>rating[i][j];

		cout<<recur(0,k,0)<<endl;

	}
}

