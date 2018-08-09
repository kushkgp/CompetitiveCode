#include <bits/stdc++.h>

using namespace std;

int bracket[25], dp[45][45];

bool found( int i, int k )
{
	for( int j = 0; j < k; j++ )
		if( bracket[j] == i )
			return true;

	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for( int i = 0; i < k; i++ )
			cin>>bracket[i];

		for( int i = 0; i <= 2*n; i++ )
			dp[i][0] = 0;

		dp[0][0] = 1;
		
		for( int i = 1; i <= 2*n; i++ )
		{
			for( int j = 1; j <= min(i,n); j++ )
			{
				if( j < (i+1)/2 )
					continue;
				if( !found(i,k) )
					dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
				else
					dp[i][j] = dp[i-1][j-1];
			}
		}

		cout<<dp[2*n][n]<<endl;
	}
}