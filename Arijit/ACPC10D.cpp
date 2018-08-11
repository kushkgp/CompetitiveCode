#include <bits/stdc++.h>

using namespace std;

long long int dp[1][3], A[100005][3];

int main()
{
	int t = 1;
	while(t)
	{
		int n;
		cin>>n;
		
		if( n == 0)
			return 0;

		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j <= 2; j++ )
				cin>>A[i][j];
		}

		dp[0][0] = INT_MAX;
		dp[0][1] = A[0][1];
		dp[0][2] = A[0][1] + A[0][2];

		long long int temp1, temp2, temp3;

		// cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;

		for( int i = 1; i < n; i++ )
		{
			temp1 = min(dp[0][0], dp[0][1]) + A[i][0];
			temp2 = min(dp[0][0], dp[0][1]);
			temp2 = min(temp2, dp[0][2]) + A[i][1];
			temp3 = min(dp[0][1], dp[0][2]) + A[i][2];
			dp[0][0] = temp1;
			dp[0][1] = temp2;
			dp[0][2] = temp3;

			dp[0][1] = min(dp[0][0] + A[i][1], dp[0][1]);
			dp[0][2] = min(dp[0][1] + A[i][2], dp[0][2]);
			
			// cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;

		}


		cout<<t<<". "<<dp[0][1]<<endl;
		t++;
	}
	return 0;
}