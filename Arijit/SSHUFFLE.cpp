#include <bits/stdc++.h>

using namespace std;

long long int dp[2005][2005];

vector <int> vec;

long long int boob( int i, int j, int a )
{
	if( i > j )
		return 0;

	if( dp[i][j]!= -1)
		return dp[i][j];

	long long int ans = max( vec[i]*a + boob(i+1,j,a+1), vec[j]*a + boob(i,j-1,a+1));
	dp[i][j] = ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(t--)
	{
		int n, temp;
		cin>>n;

		vec.clear();
		for( int i = 0; i < n; i++ )
		{
			cin>>temp;
			vec.push_back(temp);
		}
		memset(dp, -1, sizeof(dp));
		cout<<boob(0,n-1,1)<<endl;
	}
}