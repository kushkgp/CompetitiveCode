#include <bits/stdc++.h>

using namespace std;

int main()
{
	int flag = 0;
	while(1)
	{
	string s;
	cin>>s;
	flag = 0;
	int64_t ans;
	vector <int64_t> dp (5005,0);

	int n = s.length();
	// if( s[n-1] == '0' )
	// 	n--;

	if( s == "0")
		return 0;

	reverse( s.begin(), s.end() );

	dp[0] = 1;

	if(s[0]=='0')
	{
		dp[0] = 0;
		// cout<<"HELLO";
	}

	for( int i = 1; i < n; ++i )
	{
		if((  s[i] >= '3' ) && s[i-1] == '0' )
		{
			cout<<"0"<<endl;
			flag = 1;
		}

		// cout<<i<<" "<<s[i]<<endl;
		if( s[i] == '1' || (s[i]=='2' && s[i-1] <='6') )
		{
			// cout<<"dual"<<endl;
			if( i == 1 )
				dp[1] = 1;
			else
				dp[i] += dp[i-2];
		}
		
		if( s[i] != '0' )
			dp[i] += dp[i-1];
	}

	// for( int i = 0; i < n; i++ )
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	if( !flag )
		cout<<dp[n-1]<<endl;
	}
}