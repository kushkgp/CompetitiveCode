#include<bits/stdc++.h>
using namespace std;

long long solve(int arr[],int n,int elem,int hire,int salary,int sev)
{
	long long dp[n][elem+1];
	for(int i=0;i<=elem;i++)
	{
		dp[0][i] = -1;
		if(arr[0] <= i)
			dp[0][i] = i*(hire+salary);
	}

	for(int i=1;i<n;i++)
		for(int j=0;j<=elem;j++)
		{
			if(arr[i] > j)
				dp[i][j] = -1;
			else
			{
				dp[i][j] = LLONG_MAX;
				for(int k=0;k<=elem;k++)
				{
					if(dp[i-1][k] == -1)
						continue;
					long long sal = j*salary;
					if(k<=j)
						sal += hire*(j-k);
					else
						sal += sev*(k-j);
					dp[i][j] = min(dp[i][j],sal + dp[i-1][k]);
				}
			}
		}
	long long ans = LLONG_MAX;
	for(int i=arr[n-1];i<=elem;i++)
		ans = min(ans,dp[n-1][i]);
	return ans;
}

int main()
{
	int i = 1;
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int hire,salary,sev;
		scanf("%d%d%d",&hire,&salary,&sev);
		int arr[n],elem=INT_MIN;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			elem = max(elem,arr[i]);
		}
		printf("Case %d, cost = $%lld\n", i,solve(arr,n,elem,hire,salary,sev));
		i++;

	}
}