#include <bits/stdc++.h>

using namespace std;
int cylinderoxy[1005], cylindernitro[1005], weight[1005];
long long int dp[1005][105][105];

#define MAXI 1e8
int main()
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int oxy, nitro;
		cin>>oxy>>nitro;

		int n;
		cin>>n;
		for( int i = 0; i < n; i++ )
			cin>>cylinderoxy[i]>>cylindernitro[i]>>weight[i];

		for( int i = 0; i <= n; i++ )
		{
			for( int j = 0; j <= oxy; j++ )
			{
				for( int k = 0; k <= nitro; k++ )
				{
					if( j == 0 && k == 0 )
						dp[i][j][k] = 0;
					else
						if( i == 0 )
							dp[i][j][k] = MAXI;
						else
							dp[i][j][k] = min(dp[i-1][j][k], 
							weight[i-1] + dp[i-1][max(0,j-cylinderoxy[i-1])][max(0,k-cylindernitro[i-1])]);
				}
			}
		}
		cout<<dp[n][oxy][nitro]<<endl;
	}
}