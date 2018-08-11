#include <bits/stdc++.h>

using namespace std;

long long int dp[2005][2005];
string s,t;

long long int edit( int i, int j)
{
	if( i == 0 && j == 0)
		return 0;
	if( i == 0 || j == 0 )
		return max(i,j);

	if( dp[i][j] != -1 )
		return dp[i][j];

	if( s[i-1] != t[j-1] )
	{
		dp[i][j] = min(1 + edit(i-1,j-1),1 + edit(i-1,j));
		dp[i][j] = min(dp[i][j],1 + edit(i,j-1));
	}
	else
		dp[i][j] = edit(i-1,j-1);

	return dp[i][j];
}

int main()
{
	int T = 1;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		memset(dp, -1, sizeof(dp));

		// for( int i = 0; i <= n; i++ )
		// {
		// 	for( int j = 0; j <= s; j++ )
		// 	{
		// 		if( i == 0 || j == 0 )
		// 			dp[i][j] = 0;
		// 		else
		// 			if( size[i-1] <= j )
		// 			{
		// 				dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-size[i-1]]);
		// 			}
		// 			else
		// 				dp[i][j] = dp[i-1][j];
		// 	}
		// }
		
		cout<<edit(s.length(), t.length())<<endl;
	}
}