#include <bits/stdc++.h>

using namespace std;

long long int dp[105][105], inter[105][105];

int main()
{
	int n;
	while(cin>>n)
	{
		for( int i = 0; i < n; i++ )
			cin>>inter[i][i];

		int j;
		
		for( int i = 0; i < n; i++ )
			dp[i][i] = 0;

		for( int l = 2; l <= n; l++ )
		{
			for( int i = 0; i <= n - l; i++ )
			{
				j = i + l - 1;
				dp[i][j] = INT_MAX;
				for( int k = i; k < j; k++ )
				{
					if( dp[i][j] > dp[i][k] + dp[k+1][j] + inter[i][k]*inter[k+1][j] )
					{
						dp[i][j] = dp[i][k] + dp[k+1][j] + inter[i][k]*inter[k+1][j];
						inter[i][j] = (inter[i][k] + inter[k+1][j])%100;
					}
				} 
			}
		}

		cout<<dp[0][n-1]<<endl;
	}
}