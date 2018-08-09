#include <bits/stdc++.h>

using namespace std;
long long int dp[100010];
vector <long long int> vec;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, temp;
		scanf("%lld",&n);
		vec.clear();
		memset(dp, -1, sizeof(dp));
		for( int i = 0; i < n; i++ )
		{
			scanf("%lld",&temp);
			vec.push_back(temp);
		}
		
		reverse(vec.begin(), vec.end() );

		dp[0] = vec[0];
		dp[1] = dp[0] + vec[1];
		dp[2] = dp[1] + vec[2];

		for( int i = 3; i < n; i++ )
		{
			long long int maxi = vec[i] + dp[i-2];

			if( i >= 4 )
				maxi = max( maxi, vec[i] + vec[i-1] + dp[i-4] );
			else
				maxi = max( maxi, vec[i] + vec[i-1]);

			if( i >= 6 )
				maxi = max( maxi, vec[i] + vec[i-1] + vec[i-2] + dp[i-6] );
			else
				maxi = max( maxi, vec[i] + vec[i-1] + vec[i-2] );
			
			dp[i] = maxi;
		}

		// for( int i = 0; i < n; i++ )
		// 	cout<<dp[i]<<" ";
		// cout<<endl;
		printf("%lld\n",dp[n-1]);
	}
}