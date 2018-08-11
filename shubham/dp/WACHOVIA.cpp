#include<bits/stdc++.h>
using namespace std;

#define vpi vector<pair<int,int> >
#define ff first
#define ss second

int solve(vpi &v,int s,int n)
{
	int dp[s+1][n+1];
	for(int i=0;i<=s;i++)
		for(int j=0;j<=n;j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i>= v[j-1].ff)
				dp[i][j] = max(dp[i][j],v[j-1].ss + dp[i-v[j-1].ff][j-1]);
		}
	return dp[s][n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,n;
		scanf("%d%d",&s,&n);
		vpi v(n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&v[i].ff,&v[i].ss);
		printf("Hey stupid robber, you can get %d.\n", solve(v,s,n));
	}
}