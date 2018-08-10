#include<bits/stdc++.h>
using namespace std;

int max_score_smart(vector<int> &v,int n)
{
	int dp[n][n];
	for(int i = n-1;i>=0;i--)
		for(int j=i;j<n;j++)
		{
			if( i == j)
			{
				dp[i][j] = v[i];
				continue;
			}
			if( i+1 == j)
			{
				dp[i][j] = max(v[i],v[j]);
				continue;
			}
			dp[i][j] = max(v[i] + min(dp[i+2][j],dp[i+1][j-1]),v[j] + min(dp[i][j-2],dp[i+1][j-1]));
		}
	return dp[0][n-1];
}

int max_score_dumb(vector<int> &v,int n)
{
	int dp[n][n];
	for(int i = n-1;i>=0;i--)
		for(int j=i;j<n;j++)
		{
			if( i == j)
			{
				dp[i][j] = v[i];
				continue;
			}
			if( i+1 == j)
			{
				dp[i][j] = max(v[i],v[j]);
				continue;
			}
			dp[i][j] = max(v[i] + max(dp[i+2][j],dp[i+1][j-1]),v[j] + max(dp[i][j-2],dp[i+1][j-1]));
		}
	return dp[0][n-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("%d %d\n",max_score_dumb(v,n),max_score_smart(v,n));
	}
}