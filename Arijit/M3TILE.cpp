#include <bits/stdc++.h>

using namespace std;

long long int dp[505], F[35];

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if( n == -1 )
			break;

		memset(dp, -1, sizeof(dp));

		F[0] = 0;
		dp[0] = 1;

		for( int i = 1; i <= n; i++ )
		{
			dp[i] = 0;

			if( i > 1 )
				dp[i] += 3*dp[i-2];

			if( i > 2 )
				dp[i] += 2*F[i-3];

			F[i] = dp[i-1];

			if( i > 1 )
				F[i] += F[i-2];
		}

		cout<<dp[n]<<endl;
	}
}