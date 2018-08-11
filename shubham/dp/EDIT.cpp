#include<bits/stdc++.h>
using namespace std;

int solve(string &a, string &b)
{
	int n=a.size();
	int m=b.size();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(i == 0)
			{
				dp[i][j] = j;
				continue;
			}
			if(j==0)
			{
				dp[i][j] = i;
				continue;
			}
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
		}
	return dp[n][m];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		printf("%d\n", solve(a,b));
	}
}