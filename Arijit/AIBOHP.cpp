
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;

		string k =s;
		reverse(k.begin(), k.end());

		int n = s.length();

		int dp[n+1][n+1];

		for( int i = 0; i <= n; i++ )
		{
			for( int j = 0; j <= n; j++ )
			{
				if( i==0 || j==0 )
					dp[i][j]=0;
				else
					if( s[i-1] == k[j-1] )
						dp[i][j] = 1 + dp[i-1][j-1];
					else 
						dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<n - dp[n][n]<<endl;
	}
}