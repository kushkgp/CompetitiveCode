#include<bits/stdc++.h>
using namespace std;

#define mod 1988

int solve_distinct(int n,int k)
{
	n = n-k;

	int dp[k+1][n+1];

	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			if(i==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(j==0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
		}
	return dp[k][n]; 	
}

int solve(int n,int k)
{
	n = n-k;
	int dp[n+1][k+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
		{
			if(j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(i==0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i>=j)
				dp[i][j] += dp[i-j][j];
			dp[i][j] %= mod;
		}

	return dp[n][k];
}

int main()
{
	while(true)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n==0 && k==0)
			break;
		printf("%d\n",solve(n,k));
	}
}