#include <bits/stdc++.h>

using namespace std;
int dp[5001][5001];
int mod = 1988;

int solve( int i, int j )
{
	if( j == 1 )
		return 1;
	else
		if( j == 0 )
			return 0;
	else
			if( i == 0 )
			return 1;
		else if( i < 0 || j < 0 )
			return 0;

	if( dp[i][j] != -1 )
		return dp[i][j];

	dp[i][j] = ( solve(i,j-1) + solve(i-j,j) )%mod;

	return dp[i][j];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, k;
	while(1)
	{
		cin>>n>>k;
		if( n == 0 && k == 0 )
			return 0;

		solve(n,k);
		cout<<( dp[n][k] - dp[n][k-1] + mod )%mod<<endl;
	}
}