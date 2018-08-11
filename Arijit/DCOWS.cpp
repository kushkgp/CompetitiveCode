#include <bits/stdc++.h>

using namespace std;
long long int dp[5005][5005];
vector <long long int> vec, vec2;

long long int solve(int i, int j)
{
	// cout<<i<<" "<<j<<" "<<dp[i][j]<<vec.size()<<" "<<vec2.size()<<endl;
	
	if( i >= vec2.size() || j >= vec.size() )
		return 0;

	if( dp[i][j]!= -1 )
		return dp[i][j];

	long long int ans = abs(vec2[i] - vec[j]) + solve(i+1,j+1);
	
	if( vec2.size() - i > vec.size() - j )
		ans = min(ans, solve(i+1,j));
	
	dp[i][j] = ans;

	// cout<<i<<" "<<j<<" "<<ans<<endl;
	return ans;
}
int main()
{
	int t;
	t = 1;
	while(t--)
	{
		long long int n,m,temp;
		cin>>n>>m;
		vec.clear();
		vec2.clear();

		for( int i = 0; i < n; i++ )
		{
			cin>>temp;
			vec.push_back(temp);
		}
		
		for( int i = 0; i < m; i++ )
		{
			cin>>temp;
			vec2.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		sort(vec2.begin(), vec2.end());
		memset(dp, -1, sizeof(dp));
		cout<<solve(0,0)<<endl;
	}
}