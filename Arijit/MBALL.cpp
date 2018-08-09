#include <bits/stdc++.h>

using namespace std;
long long int dp[10][100005];

int n, m;
int changes[5] = {2,3,6,7,8};

int martian( int n, int count )
{
	if( n == 0)
	{
		dp[count][n] = 1;
		return 1;
	}

	if( n < 0 || count > 5)
		return 0;
	

	if( dp[count][n] != -1 )
		return dp[count][n];

	long long int x = martian(n, count + 1);
	long long int y = martian(n-changes[count-1],count);

	dp[count][n] = x + y;
	return dp[count][n];
}

int main()
{
	int t = 1;
	cin>>t;
	memset(dp, -1, sizeof(dp) );
	while(t--)
	{
		cin>>n;
		cout<<martian(n,1)<<endl;
	}
}
