#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int> >
#define vi vector<int>

long long solve(vvi &v,int n)
{
	long long dp[n+1][5];
	for(int i=0;i<=n;i++)
		for(int j=0;j<5;j++)
		{
			if(i == 0)
			{
				dp[i][j] = LLONG_MAX;
				continue;
			}
			if(j==0 || j==4)
			{
				dp[i][j] = LLONG_MAX;
				continue;
			}
			if( i==1 && j== 2)
			{
				dp[i][j] = v[i-1][j-1];
				continue;
			}
			dp[i][j] = LLONG_MAX;
			if(dp[i][j-1] != LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i][j-1]);
			if(dp[i-1][j-1] != LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
			if(dp[i-1][j] != LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i-1][j]);
			if(dp[i-1][j+1] != LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
			if(dp[i][j] != LLONG_MAX)
				dp[i][j] += v[i-1][j-1];
		}

	return dp[n][2];
}

int main()
{

	int i =1;
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
			break;
		vvi v(n,vi(3));
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
		printf("%d. %lld\n",i,solve(v,n) );
		i+=1;
	}
}