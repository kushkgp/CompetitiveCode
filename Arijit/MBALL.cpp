#include <bits/stdc++.h>

using namespace std;
long long int dp[10][100005];

int n, m;
int changes[5] = {2,3,6,7,8};

int martian( int n, int count )
{
	if( n == 0)
	{
		dp[count][0] = 1;
		return 1;
	}

	if( count == 0 )
	{
		dp[0][n] = 0;
		return 0;
	}
	if( n < 0 || count < 0 ) 
		return 0;

	if( dp[count][n] != -1 )
		return dp[count][n];

	long long int x = 0, y = 0;
	
	x = martian(n, count - 1);
	if( changes[count-1] <= n )
	{
		y = martian(n-changes[count-1],count);
	}

	dp[count][n] = x + y;
	return dp[count][n];
}

int main()
{
	int t = 1;
	cin>>t;
	while(t--)
	{
		memset(dp, -1, sizeof(dp) );
		cin>>n;
		// cout<<martian(n,5)<<endl;
		for( int i = 0; i <=n; i++ )
			dp[0][i] = 0;
		
		for( int i = 0; i <=5; i++ )
			dp[i][0] = 1;

		for( int i = 1; i <= 5; i++ )
		{
			for( int j = 1; j <= n; j++ )
			{
					if( changes[i-1] <= j )
					{
						dp[i][j] = dp[i-1][j] + dp[i][j-changes[i-1]];
					}
					else
						dp[i][j] = dp[i-1][j];
			}
		}
		cout<<dp[5][n]<<endl;
	}
}
