#include <bits/stdc++.h>

using namespace std;

long long int dp[10005], val[505], wt[505];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w1, w2, n;
		cin>>w1>>w2;
		cin>>n;

		int w = w2 - w1;

		memset(dp, -1, sizeof(dp));

		for( int i = 0; i < n; i++ )
		{
			cin>>val[i]>>wt[i];
		}

		dp[0] = 0;

		for( int i = 1; i <= w; i++ )
		{
			dp[i] = INT_MAX;
			for( int j = 0; j < n; j++ )
			{
				if( wt[j] <= i )
					dp[i] = min(dp[i], val[j] + dp[i-wt[j]]);
			}
			// cout<<i<<" "<<dp[i]<<endl;
		}

		if( dp[w] == INT_MAX)
			cout<<"This is impossible.\n"<<endl;
		else
			printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[w]);
		
	}
}