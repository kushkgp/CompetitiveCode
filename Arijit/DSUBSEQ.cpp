#include <bits/stdc++.h>

using namespace std;
long long int dp[100005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		long long int mod = 1000000007;
		// unordered_map <char,int> last;
		dp[0] = 1;
		dp[1] = 2;
		// last[s[0]] = 0;

		for( int i = 2; i <= n; i++ )
		{
			long long int count = 0;
			for( int j = i - 1; j > 0; j--)
				if( s[j-1] == s[i-1] )
				{
					count = dp[j-1];
					break;
				}
			dp[i] = ((2*dp[i-1])%mod - count + mod )%mod;
		}

		cout<<dp[n]<<endl;
	}
}