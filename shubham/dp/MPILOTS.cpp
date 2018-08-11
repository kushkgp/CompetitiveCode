#include<bits/stdc++.h>
using namespace std;

#define vpi vector<pair<int,int> >
#define ff first
#define ss second

long long solve(vpi &v,int n)
{
	long long dp[n+1][n+1];
	for(int i=n;i>0;i--)
		for(int j =0 ; j<i;j++)
		{
			if(i == n)
			{
				if(j == 1)
					dp[i][j] = v[i-1].ff;
				else
					dp[i][j] = LLONG_MAX;
				continue;
			}
			dp[i][j] = LLONG_MAX;
			if(dp[i+1][j+1] != LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i+1][j+1] + v[i-1].ss);
			if(j>0 && dp[i+1][j-1]!=LLONG_MAX)
				dp[i][j] = min(dp[i][j],dp[i+1][j-1] + v[i-1].ff);
		}
	return dp[1][0];
}

int main()
{
	int n;
	scanf("%d",&n);
	vpi v(n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&v[i].ff,&v[i].ss);
	printf("%lld\n", solve(v,n));
}