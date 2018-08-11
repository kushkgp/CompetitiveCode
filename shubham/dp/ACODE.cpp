#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(true)
	{
		cin>>s;
		if(s== "0")
			break;
		s = "-" + s;
		// cout<<s.size()<<endl;
		int dp[s.size()];
		memset(dp,0,sizeof dp);
		dp[0] = 1;
		int n = s.size();
		for(int i=1;i<n;i++)
		{
			if(s[i] != '0')
				dp[i] += dp[i-1];
			if(s[i] <= '6' && s[i-1] == '2')
				dp[i] += dp[i-2];
			if(s[i-1] == '1')
				dp[i] += dp[i-2];

		}
		cout<<dp[n-1]<<endl;
	}
}