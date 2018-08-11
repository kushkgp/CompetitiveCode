#include <bits/stdc++.h>

using namespace std;

int dp[1005], prefix[1005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		memset(dp,-1,sizeof(dp));
		cin>>s;

		dp[0] = 0;
		prefix[0] = 0;
	
		for( int i = 1; i <= n; i++ )
		{
			prefix[i] = prefix[i-1] + s[i-1] - '0';
		}

		for( int i = 1; i <= n; i++ )
		{
			dp[i] = dp[i-1];

			for( int j = i; j > 0; j-- )
			{
				if( prefix[i] - prefix[j-1] > (i-j+1)/2 )
				{
					dp[i] = max(dp[i], dp[j-1] + i-j+1);
				}
			}
		}

		cout<<dp[n]<<endl;
	}
}