#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];

int main()
{
	int t;
	int n, k, mod = 1988;

	for(int k = 0; k < 5001; k++)
	{
		dp[k][1] = 1;
		dp[0][k] = 1;
	}
	
	for( int j = 2; j < 5001; j++ )
	{
		for( int i = 1; i < 5001; i++ )
		{
			if( i < j )
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = ( dp[i-j][j] + dp[i][j-1] )%mod;
		}
	}

	while(true)
	{
		cin>>n>>k;
		if(!n && !k) break;
		cout<<( dp[n][k] - dp[n][k-1] + mod )%mod<<endl;
	}
}