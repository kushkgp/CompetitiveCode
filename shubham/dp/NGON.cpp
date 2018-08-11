#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(int sum,int n)
{
	int dp[sum+1][n];
	for(int i=0;i<=sum;i++)
		for(int j=0;j<n;j++)
		{
			if(j ==0)
			{
				dp[i][j] = 1;
				continue;
			}
			if(i == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
		}

	return dp[sum][n-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		int n;
		scanf("%d",&n);
		int arr[n];
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+= arr[i];
		}
		printf("%d\n", solve(sum,n));
	}
}