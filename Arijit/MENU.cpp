#include <bits/stdc++.h>
using namespace std;

long long int dp[50][3][25][105];

long long int dish[55][2];
int main()
{
	while(1)
	{
		long long int k,n,m;
		cin>>k>>n>>m;
		if( k == 0 && n==0 && m==0 )
			return 1;

		for( int i = 0; i < n; i++ )
		{
			cin>>dish[i][0];
			cin>>dish[i][1];
		}

		memset(dp, -1, sizeof(dp));


}