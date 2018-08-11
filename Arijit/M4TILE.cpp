#include <bits/stdc++.h>

using namespace std;

long long int dp[35], F[35], G[35];

int main()
{
	int n,t;
	cin>>t;
	int k = 1;
	while(k <= t)
	{
		cin>>n;
		memset(dp, -1, sizeof(dp));

		// F[1] = 0;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 5;
		dp[3] = 11;
		// G[1] = 1;

		for( int i = 4; i <= n; i++ )
		{
			dp[i] = dp[i-1];

			if( i > 1 )
				dp[i] += 5*dp[i-2];

			if( i > 2 )
				dp[i] += dp[i-3];

			if( i > 3) 
				dp[i] -= dp[i-4];
			// cout<<i<<" "<<dp[i]<<endl;
		}

		cout<<k<<" "<<dp[n]<<endl;
		k++;
	}
}