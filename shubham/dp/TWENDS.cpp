#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int solve(vi &v,int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += v[i];
	int dp[n][n];
	for(int i=n-1;i>=0;i--)
		for(int j=i+1;j<n;j++)
		{
			if(i==j)
			{
				dp[i][j] = v[i];
				continue;
			}
			if( i+1 == j)
			{
				dp[i][j] = max(v[i],v[j]);
				continue;
			}
			int t,k;
			if(v[i+1] == v[j])
				t = dp[i+2][j];
			else
				t = (v[i+1]>v[j])?dp[i+2][j]:dp[i+1][j-1];
			if(v[j-1] == v[i])
				k = dp[i+1][j-1];
			else
				k = (v[j-1]>v[i])?dp[i][j-2]:dp[i+1][j-1];
			dp[i][j] = max(t + v[i],k + v[j]);

		}
	// cout<<sum<<endl;
	// cout<<dp[0][n-1]<<endl;
	return (dp[0][n-1]<<1) - sum;
}

int main()
{	
	int i =1;
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		vi v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", i,solve(v,n));
		i+=1;

	}
}