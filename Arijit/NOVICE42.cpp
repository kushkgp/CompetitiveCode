#include <bits/stdc++.h>

using namespace std;

long long int dp[15][15] ;
int n;
		
long long int recur( int in, int x )
{
	if( in == n )
	{
		dp[n][x] = x+1;
		return x+1;
	}
	if( dp[in][x]!= -1 )
		return dp[in][x];

	dp[in][x] = x*recur(in+1,x);
	if( x < in )
		dp[in][x] += recur(in+1,x+1);

	return( dp[in][x] );
}

int main()
{
	int t = 1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset( dp, -1, sizeof(dp) );
        if( n == 1 )
        	cout<<1<<endl;
    	else
        	cout<<recur(1,1)<<endl;
    }
  	
}
	