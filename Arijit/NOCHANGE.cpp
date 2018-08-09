#include <bits/stdc++.h>

using namespace std;

int dp[100005], prefix[100005];
vector <int> vec;

int change( int n )
{
	if( n < 0 )
		return 0;

	if( n == 0)
		return 1;

	if( dp[n] != -1 )
		return dp[n];

	dp[n] = 0;
	
	for( int i = 1; i <= vec.size(); i++ )
	{
		if(change(n-prefix[i]) == 1)
		{
			dp[n] = 1;
			return dp[n];
		}
	}
	return dp[n];
}


int main()
{
	int t = 1;
	while(t--)
	{
		int n, k, temp;
		cin>>n>>k;
		
		for( int i = 0; i < k; i++ )
		{
			cin>>temp;
			vec.push_back(temp);
		}

		prefix[0] = 0;
	
		for( int i = 1; i <= k; i++ )
		{
			prefix[i] = prefix[i-1] + vec[i-1];
		}
		
		memset(dp, -1, sizeof(dp));
		dp[0] = 1;
		
		if( change(n) > 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}