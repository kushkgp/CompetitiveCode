#include<bits/stdc++.h>
using namespace std;

#define vpii vector<pair<int,int> >

int solve(int pigi,int total,int coins, vpii &coin)
{
	int sum = total-pigi;
	int dp[sum+1][coins+1];
	for(int i=0;i<=sum;i++)
		for(int j=0;j<=coins;j++)
		{
			if(i == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(j == 0)
			{
				dp[i][j] = INT_MAX;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i >= coin[j-1].second && dp[i-coin[j-1].second][j] != INT_MAX)
				dp[i][j] = min(dp[i][j] , coin[j-1].first + dp[i-coin[j-1].second][j]);
		}
	return dp[sum][coins];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int pigi,total;
		scanf("%d%d",&pigi,&total);
		int coins;
		scanf("%d",&coins);
		vpii coin(coins);
		for(int i=0;i<coins;i++)
			scanf("%d%d",&coin[i].first,&coin[i].second);
		int ans = solve(pigi,total,coins,coin);
		if(ans == INT_MAX)
			printf("This is impossible.\n" );
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", ans);

	}
}