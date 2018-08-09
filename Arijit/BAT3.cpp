#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, temp;
		cin>>n>>m;

		int vec[n+1][m+1], dp[n+1][m+1];
		memset( dp, -1, sizeof(dp));

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
			{
				cin>>temp;
				vec[i][j] = temp;
			}

		for( int j = 0; j < m; j++ )
			dp[n-1][j] = vec[n-1][j];

		for( int i = n - 2; i >= 0; i-- )
		{
			for( int j = 0; j < m; j++ )
			{
				if( j == 0 )
					dp[i][j] = vec[i][j] + max( dp[i+1][j+1], dp[i+1][j]);
				else
					if( j == m-1 )
						dp[i][j] = vec[i][j] + max( dp[i+1][j], dp[i+1][j-1]);
					else
					{
						int temp = max(dp[i+1][j-1], dp[i+1][j+1]);
						dp[i][j] = vec[i][j] + max( dp[i+1][j], temp);
					}
			}
		}

		int maxi = 0;

		for( int i = 0; i < m; i++)
			maxi = max( dp[0][i], maxi );

		cout<<maxi<<endl;
	}
}