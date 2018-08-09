#include <bits/stdc++.h>

using namespace std;

long long int dp[55][1005], size[55], value[55];

int main()
{
	int t = 1;
	cin>>t;
	while(t--)
	{
		int s, n;
		cin>>s>>n;
		if( s==0 && n==0 )
			return 0;

		memset(dp, 0, sizeof(dp));

		for( int i = 0; i < n; i++ )
		{
			cin>>size[i]>>value[i];
		}

		memset(dp, 0, sizeof(dp) );

		for( int i = 0; i <= n; i++ )
		{
			for( int j = 0; j <= s; j++ )
			{
				if( i == 0 || j == 0 )
					dp[i][j] = 0;
				else
					if( size[i-1] <= j )
					{
						dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-size[i-1]]);
					}
					else
						dp[i][j] = dp[i-1][j];
			}
		}
		
		cout<<"Hey stupid robber, you can get "<<dp[n][s]<<"."<<endl;
	}
}