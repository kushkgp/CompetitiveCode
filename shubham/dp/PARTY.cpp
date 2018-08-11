#include<bits/stdc++.h>
using namespace std;

#define vpi vector<pair<int,int> >
#define ff first
#define ss second

pair<int,int> solve(vpi &v,int budget,int parties)
{
	int dp[budget+1][parties+1],cost[budget+1][parties+1];
	for(int i=0;i<=budget;i++)
		for(int j=0;j<=parties;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
				cost[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			cost[i][j] = cost[i][j-1];
			if(i>=v[j-1].ff)
			{
				int t = v[j-1].ss + dp[i - v[j-1].ff][j-1];
				int c = v[j-1].ff + cost[i - v[j-1].ff][j-1];
				if(t > dp[i][j])
				{
					dp[i][j] = t;
					cost[i][j] = c;
				}
				else if( t == dp[i][j])
					cost[i][j] = min(cost[i][j],c);
			}
		}
	pair<int,int> ans;
	ans.ff = cost[budget][parties];
	ans.ss = dp[budget][parties];
	return ans;
}

int main()
{
	while(true)
	{
		int budget,parties;
		scanf("%d%d",&budget,&parties);
		if(budget == 0 && parties == 0)
			break;
		vpi v(parties);
		for(int i=0;i<parties;i++)
			scanf("%d%d",&v[i].ff,&v[i].ss);
		pair<int,int> ans = solve(v,budget,parties);
		printf("%d %d\n", ans.ff,ans.ss);
	}
}