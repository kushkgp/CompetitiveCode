#include <bits/stdc++.h>

using namespace std;

long long int dp[100005], val[15], wt[15];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w, y, n;
		cin>>w>>y;
		cin>>n;

		long long int money = w;

		w = w/1000;
		memset(dp, -1, sizeof(dp));

		for( int i = 0; i < n; i++ )
		{
			cin>>wt[i]>>val[i];

			wt[i] = wt[i]/1000;
		}

		dp[0] = 0;

		for( int i = 1; i <= 90*w; i++ )
		{
			dp[i] = 0;
			for( int j = 0; j < n; j++ )
			{
				if( wt[j] <= i )
					dp[i] = max(dp[i], val[j] + dp[i-wt[j]]);
			}
			// cout<<i<<" "<<dp[i]<<endl;
		}

		for( int i = 1; i <= y; i++ )
		{
			money = money + dp[money/1000];
			// cout<<money<<endl;
		}

		cout<<money<<endl;
	}
}