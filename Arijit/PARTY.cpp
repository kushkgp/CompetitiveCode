#include <bits/stdc++.h>

using namespace std;

long long int dp[105][505], cost[105], fun[105];

int main()
{
	int t = 1;
	while(t)
	{
		int b, n;
		cin>>b>>n;
		if( b==0 && n==0 )
			return 0;

		memset(dp, 0, sizeof(dp));

		for( int i = 0; i < n; i++ )
		{
			cin>>cost[i]>>fun[i];
		}

		for( int i = 0; i <= n; i++ )
		{
			for( int w = 0; w <= b; w++ )
			{
				if( i == 0 || w == 0)
					dp[i][w] = 0;
					
				else if( cost[i-1] <= w )
					dp[i][w] = max(dp[i-1][w], fun[i-1] + dp[i-1][w-cost[i-1]]);
				else
					dp[i][w] = dp[i-1][w];
			}
		}

		int MAXFUN = -1, MAXCOST = 0;
		for( int i = b; i >= 0; i-- )
		{
			if( dp[n][i] >= MAXFUN )
			{
				MAXFUN = dp[n][i];
				MAXCOST = i;
			}
		}
		cout<<MAXCOST<<" "<<MAXFUN<<endl;
	}
}