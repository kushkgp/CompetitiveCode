#include <bits/stdc++.h>

using namespace std;

long long int arr[105], dp[105][105][105] ;
int n;
		
long long int recur( int in, int x, int y)
{
	if( in == n+1 )
		return 0;

	if( dp[in][x][y] != -1 )
		return dp[in][x][y];

	dp[in][x][y] = recur(in+1,x,y);

	if( x == 0 )
		dp[in][x][y] = max(dp[in][x][y], 1 + recur(in+1, in, y));

	if( y == 0 )
		dp[in][x][y] = max(dp[in][x][y], 1 + recur(in+1, x, in));

	if( arr[in] > arr[x] && x > 0 )
		dp[in][x][y] = max( dp[in][x][y], 1 + recur(in+1,in,y));

	if( arr[in] < arr[y] && y > 0 )
		dp[in][x][y] = max( dp[in][x][y], 1 + recur(in+1,x,in));

	return( dp[in][x][y] );
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;

		for( int i = 1; i <= n; i++ )
			cin>>arr[i];

		memset( dp, -1, sizeof(dp) );
        cout<<recur(1,0,0)<<endl;
    }
  	
}
	