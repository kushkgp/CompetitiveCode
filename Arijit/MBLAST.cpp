#include <bits/stdc++.h>

using namespace std;

long long int dp[2005][2005];

int LCS( string A, string B, int K)
{
	for( int i = 0; i <= A.length(); i++ )
	{
		for( int j = 0; j <= B.length(); j++ )
		{
			if( i==0 || j==0 )
				dp[i][j]= K*max(i,j);
			else
				{
					dp[i][j] = min(dp[i-1][j-1] + (int)abs((double)(A[i - 1] - B[j - 1])), min(dp[i-1][j]+K,dp[i][j-1]+K));
				}
		}
	}

	return( dp[A.size()][B.size()]);
}
int main()
{
	int t = 1;
	while(t--)
	{
		string s,t;
		int K;
		cin>>s>>t>>K;
		long long int ans = LCS(s,t,K);
		cout<<ans<<endl;
	}
}