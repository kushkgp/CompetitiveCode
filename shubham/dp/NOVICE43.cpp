#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int dp[n+1][26];;
	for(int i=0;i<=n;i++)
		for(int j=0;j<26;j++)
		{
			if(j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			if(i == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 0;	
			dp[i][j] += dp[i-1][j] * (j+1);
			dp[i][j] += dp[i-1][j-1];
		}
	int sum = 0;
	for(int j=0;j<26;j++)
	{
		sum += dp[n-1][j];
		// cout<<dp[n-1][j]<<endl;
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n", solve(n));
	}
}