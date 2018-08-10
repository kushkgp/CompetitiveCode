#include<bits/stdc++.h>
using namespace std;

int arr[] = { 2 , 3 , 6, 7, 8};

long long solve(int n)
{
	long long dp[n+1][6];
	for(int i=0;i<=n;i++)
		for(int j=0;j<6;j++)
		{
			if(i == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			if( j == 0 )
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1])
				dp[i][j] += dp[i-arr[j-1]][j];

		}
	return dp[n][5];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n", solve(n));
	}
}