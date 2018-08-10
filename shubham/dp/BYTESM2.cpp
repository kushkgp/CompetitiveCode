#include<bits/stdc++.h>
using namespace std;

int max_stones(vector<vector<int> > &tiles,int n,int m)
{
	int dp[n+1][m+2];
	for(int i=0;i<n+1;i++)
		memset(dp[i],0,sizeof dp[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = tiles[i-1][j-1] + max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
		}
	int ans = INT_MIN;
	for(int i=0;i< m+2 ; i++)
		ans = max(ans,dp[n][i]);
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector<vector<int> > tiles(n,vector<int>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&tiles[i][j]);
				// cin>>tiles[i][j];
			}
		printf("%d\n",max_stones(tiles,n,m));
	}
}