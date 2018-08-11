#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.size();
		int dp[n+1][n];
		for(int i=0;i<=n;i++)
			memset(dp[i],0,sizeof dp[i]);
		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++)
			{
				if(s[i] == s[j])
					dp[i][j] = dp[i+1][j-1];
				else 
					dp[i][j] = 1 + min(dp[i][j-1],dp[i+1][j]);
			}
		cout<<dp[0][n-1]<<endl;
	}
}