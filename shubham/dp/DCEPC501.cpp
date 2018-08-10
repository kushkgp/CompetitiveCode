#include<bits/stdc++.h>
using namespace std;

long long max_toys(vector<int> &v, int n)
{
	long long dp[n+10];
	memset(dp,0,sizeof dp);
	for(int i=n-1;i>=0;i--)
	{
		dp[i] = max(max(v[i]+dp[i+2],v[i]+v[i+1] + dp[i+4]),v[i] + v[i+1] + v[i+2] + dp[i+6]);
	}
	return dp[0];

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> v(n+10,0);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("%lld\n", max_toys(v,n));
	}
}