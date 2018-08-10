#include<bits/stdc++.h>
using namespace std;

long long find_min_diff(vector<int> &bull,vector<int> &cow,int n,int m)
{
	long long dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i == 0 &&j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(i == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(j == 0)
			{
				dp[i][j] = 6000000010;
				continue;
			}
			dp[i][j] = min(abs(bull[i-1] - cow[j-1])+dp[i-1][j-1],dp[i][j-1]);
		}
	return dp[n][m];
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> bull(n),cow(m);
	for(int i=0;i<n;i++)
		scanf("%d",&bull[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&cow[i]);
	sort(bull.begin(), bull.end());
	sort(cow.begin(), cow.end());
	printf("%lld\n", find_min_diff(bull,cow,n,m));
}