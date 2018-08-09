#include <bits/stdc++.h>

using namespace std;
int a[1005], b[1005];
long long int dp[1005][2];

int main()
{
	int n;
	cin>>n;

	for( int i = 0; i < n; i++ )
		cin>>a[i]>>b[i];

	dp[0][0] = a[0] + b[0];
	dp[0][1] = a[0] + b[0];

	for( int i = 1; i < n; i++ )
	{
		dp[i][0] = max(dp[i-1][0] - a[i-1] + abs(a[i-1] - a[i]), dp[i-1][1] - b[i-1] + abs(b[i-1] - a[i]));
		dp[i][0] = dp[i][0] + b[i] + a[i];

		dp[i][1] = max(dp[i-1][0] - a[i-1] + abs(a[i-1] - b[i]), dp[i-1][1] - b[i-1] + abs(b[i-1] - b[i]));
		dp[i][1] = dp[i][1] + b[i] + a[i];
	}

	cout<<max(dp[n-1][0] - a[n-1], dp[n-1][1] - b[n-1])<<endl;
}