#include<bits/stdc++.h>
using namespace std;

struct data{
	int ox;
	int nit;
	int wt;
};
#define vd vector<data>

int solve(vd &v,int o2,int n2,int n)
{
	int dp[o2+1][n2+1][n+1];
	for(int i=0;i<=o2;i++)
		for(int j=0;j<=n2;j++)
			for(int k=0;k<=n;k++)
			{
				if(i == 0 && j == 0)
				{
					dp[i][j][k] = 0;
					continue;
				}
				if(k == 0 )
				{
					dp[i][j][k] = INT_MAX;
					continue;
				}
				dp[i][j][k] = dp[i][j][k-1];
				int t = (i>=v[k-1].ox)? i - v[k-1].ox : 0 ;
				int p = (j>=v[k-1].nit)? j - v[k-1].nit : 0 ;
				if(dp[t][p][k-1] != INT_MAX)
					dp[i][j][k] = min(dp[i][j][k],dp[t][p][k-1] + v[k-1].wt);
			}
	return dp[o2][n2][n];
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int o2,n2,n;
		scanf("%d%d",&o2,&n2);
		scanf("%d",&n);
		vd v(n);
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&v[i].ox,&v[i].nit,&v[i].wt);
		printf("%d\n", solve(v,o2,n2,n));
	}
}