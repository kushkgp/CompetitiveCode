#include <bits/stdc++.h>

using namespace std;

long long int dp[1005][1005];
string s,t;
#define MAX 1e8
int LCS( int i, int j)
{

	if( i >= s.length() )
		return MAX;
	if( j >= t.length() )
		return 1;

 	if( dp[i][j] != -1 )
 		return dp[i][j];
	
	int ans = MAX;
	int m;
	for( m = j; m < t.length(); m++)
		if( t[m] == s[i] )
		{
			ans = min(ans, 1 + LCS(i+1,m+1));
			break;
		}

	if( m == t.length() )
		ans = 1;

	dp[i][j] = min(ans, LCS(i+1,j));
   
	return dp[i][j];

}
int main()
{
	cin>>s;
	cin>>t;

	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::transform(t.begin(), t.end(), t.begin(), ::tolower);

	memset(dp, -1, sizeof(dp));

	int ans = LCS(0,0);
	cout<<ans<<endl;
}