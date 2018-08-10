#include<bits/stdc++.h>
using namespace std;

int solve(string &s1,string &s2,string &s3)
{
	int n = s1.size();
	int m = s2.size();
	int l = s3.size();
	int dp[n+1][m+1][l+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=l;k++)
			{
				if(i == 0)
				{
					dp[i][j][k] = 1;
					continue;
				}
				if(j == 0 && k == 0)
				{
					dp[i][j][k] = 0;
					continue;
				}
				dp[i][j][k] = 0;
				for(int t=j-1;t>=0;t--)
					if(s2[t] == s1[i-1]) dp[i][j][k] += dp[i-1][t][k];
				for(int t=k-1;t>=0;t--)
					if(s3[t] == s1[i-1]) dp[i][j][k] += dp[i-1][j][t];

				
			}
	return dp[n][m][l];
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		printf("%d\n", solve(s3,s1,s2));
	}
}