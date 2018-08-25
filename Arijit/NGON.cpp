#include <bits/stdc++.h>

using namespace std;

long long int A[1005], dp[1005][1005];

long long int MOD = 1000000007;

long long int recur( int a, int b )
{

	for( int i = 0; i <= a; i++ )
	{
		for( int j = 0; j <= b; j++ )
		{
			if( j == 0 )
			{
				dp[i][j] = 1;
				continue;
			}
			else
				if( i == 0 )
				{
					dp[i][j] = 0;
					continue;
				}
			dp[i][j] = dp[i-1][j];
			dp[i][j] += A[i-1]*dp[i-1][j-1];
			if( j > 1 )
				dp[i][j] += ((A[i-1]*(A[i-1]-1))/2)*dp[i-1][j-2];

			dp[i][j] = dp[i][j]%MOD;
		}
	}
	// if( b == 0 )
	// 	return 1;
	// else
	// 	if( a == 0 )
	// 		return 0;

	// if( dp[a][b] != -1 )
	// 	return dp[a][b];

	// long long int ans3 = 0;

	// long long int ans1 = recur(a-1,b);
	// long long int ans2 = (A[a-1]*recur(a-1,b-1))%MOD;
	
	// if( b > 1 )
	// {
	// 	ans3 = ((A[a-1]*(A[a-1]-1)/2))%MOD;
	// 	ans3 = (ans3*recur(a-1,b-2))%MOD;
	// }

	// dp[a][b] = ((ans1 + ans2)%MOD + ans3)%MOD;

	return dp[a][b];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		for( int i = 0; i < n; i++ )
			cin>>A[i];
		memset(dp, 0, sizeof(dp));
		cout<<recur(n, n-1)<<endl;
	}
}