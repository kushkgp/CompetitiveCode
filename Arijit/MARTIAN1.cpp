#include <bits/stdc++.h>

using namespace std;
long long int YEYE[505][505], BLOG[505][505], yeye[505][505], blog[505][505], dp[505][505];

int n, m;

int martian( int n, int m )
{
	long long int sum = 0, tmp1, tmp2;

	for( int i = 0 ; i <= n; i++ )
	{
		for( int j = 0; j <= m; j++ )
		{
			int tmp1 = blog[i][j];
			int tmp2 = yeye[i][j];

			if( i > 0 )
				tmp2 += dp[i-1][j];

			if( j > 0 )
				tmp1 += dp[i][j-1];

			dp[i][j] = max(tmp1, tmp2);
		}
	}
	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(1)
	{
		int temp;
		cin>>n>>m;

		if( n==0 && m==0)
			return 0;

		long long int sum = 0;

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin>>YEYE[i][j];	

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin>>BLOG[i][j];

		for( int i = 0; i < n; i++ )
		{
			yeye[i][0] = YEYE[i][0];
			for( int j = 1; j < m; j++ )
			{
				yeye[i][j] = yeye[i][j-1] + YEYE[i][j];
			}
		}

		for( int i = 0; i < m; i++ )
		{
			blog[0][i] = BLOG[0][i];
			for( int j = 1; j < n; j++ )
			{
				blog[j][i] = blog[j-1][i] + BLOG[j][i];
			}
		}

		memset(dp, -1, sizeof(dp));
		cout<<martian(n-1,m-1)<<endl;

		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
