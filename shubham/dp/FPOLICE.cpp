#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int> > 

void solve(vvi &Time, vvi &Risk, int n,int T)
{
	long long dp[T+1][n];
	int tym[T+1][n];
	for(int t=0;t<=T;t++)
	{
		for(int i=0;i<n;i++)
		{
			if(t==0)
			{
				if(i == n-1)
				{
					dp[t][i] = 0;
					tym[t][i] = 0;
					continue;
				}
				else
				{
					dp[t][i] = LLONG_MAX;
					tym[t][i] = INT_MAX;
					continue;
				}
			}
			if(t >= Time[i][n-1])
			{
				dp[t][i] = Risk[i][n-1];
				tym[t][i] = Time[i][n-1];
			}
			else
			{
				dp[t][i] = LLONG_MAX;
				tym[t][i] = INT_MAX;
			}
			for(int k=0;k<n;k++)
			{
				if(i == k)
					continue;
				if(t>=Time[i][k] && dp[t-Time[i][k]][k] != LLONG_MAX)
				{
					// dp[t][i] = min(dp[t][i],dp[t-Time[i][k]][k] + Risk[i][k]);
					long long temp = dp[t-Time[i][k]][k] + Risk[i][k];
					if(temp < dp[t][i])
					{
						dp[t][i] = temp;
						tym[t][i] = tym[t-Time[i][k]][k] + Time[i][k];
					}
					if(temp == dp[t][i])
					{
						tym[t][i] = min(tym[t][i],tym[t-Time[i][k]][k] + Time[i][k]);
					}
				}
			}
		}
	}
	if(dp[T][0] != LLONG_MAX)
		printf("%lld %d\n", dp[T][0],tym[T][0]);
	else
		printf("-1\n" );
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,T;
		scanf("%d%d",&n,&T);
		vvi Time(n,vector<int>(n)),Risk(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&Time[i][j]);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&Risk[i][j]);
		solve(Time,Risk,n,T);
	}
}