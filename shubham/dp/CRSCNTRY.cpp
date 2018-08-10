#include<bits/stdc++.h>
using namespace std;

int find_meetings(vector<int> &agnes_routes, vector<int> & tom_route)
{
	int n = agnes_routes.size();
	int m = tom_route.size();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(agnes_routes[i-1] == tom_route[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	return dp[n][m];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> agnes_routes;
		while(true)
		{
			int x;
			scanf("%d",&x);
			if(x == 0)
				break;
			agnes_routes.push_back(x);
		}
		vector<vector<int> > tom_routes;
		while(true)
		{
			int x;
			scanf("%d",&x);
			if(x == 0)
				break;
			vector<int> route;
			route.push_back(x);
			while(true)
			{
				int y;
				scanf("%d",&y);
				if(y == 0)
					break;
				route.push_back(y);
			}
			tom_routes.push_back(route);
		}
		int n = tom_routes.size();
		int ans = INT_MIN;
		for(int i=0;i<n;i++)
			ans = max(ans,find_meetings(agnes_routes,tom_routes[i]));
		printf("%d\n", ans);	
	}
}