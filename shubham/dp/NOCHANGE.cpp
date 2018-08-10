#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int x)
{
	int dp[n+1][x+1];
	int sum[x+1];
	sum[0] = 0;
	for(int i=1;i<=x;i++)
		sum[i] = sum[i-1] + arr[i-1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=x;j++)
		{
			if(i == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			if(j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i >= sum[j])
				dp[i][j] |= dp[i-sum[j]][j];
		}
	return dp[n][x];
}

int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	int  arr[x];
	for(int i=0;i<x;i++)
		scanf("%d",&arr[i]);
	if(solve(arr,n,x))
		printf("YES\n");
	else
		printf("NO\n");
}