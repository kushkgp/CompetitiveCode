#include <bits/stdc++.h>

using namespace std;

long long int salary[10005][2], dp[10005][5005];

#define MAX 1e9 + 5

int main()
{
	int t = 1;
	while(t--)
	{
		int n;
		cin>>n;
		for( int i = 0; i < n; i++ )
			cin>>salary[i][1]>>salary[i][0];


		memset(dp, MAX, sizeof(dp));

		for( int i = 0; i <= n; i++ )
			dp[i][0] = MAX;


		dp[0][0] = 0;
		
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= min(i,n/2); j++ )
			{
				if( j < (i+1)/2 )
					continue;
				dp[i][j] = min(salary[i-1][1] + dp[i-1][j], salary[i-1][0] + dp[i-1][j-1]);
			}
		}
		
		cout<<dp[n][n/2]<<endl;
	}
}