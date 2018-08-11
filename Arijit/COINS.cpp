#include <bits/stdc++.h>

using namespace std;

long long int dp[1000003];


long long int coins( long long int n)
{
	if( n <= 1000000)
		return(dp[n]);

	long long int temp = coins(n/2) + coins(n/3) + coins(n/4);
	return(max(n,temp));
}

int main()
{
	dp[0] = 0;
	for( long long int i = 1; i <= 1000000; i++ )
	{
		long long int temp = dp[i/2] + dp[i/3] + dp[i/4];
		dp[i] = max(i, temp);
	}

	long long int n;
	while(cin>>n)
	{
		if( n < 0)
			return 0;
		cout<<coins(n)<<endl;
		n = -1;
	}
}