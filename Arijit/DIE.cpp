#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005][3];

int recur( int H, int A, int last)
{
	if( H <= 0 || A <= 0 )
		return 0;

	if( dp[H][A][last] != -1 )
		return dp[H][A][last];
	long long int ans;
	if( last == -1 )
		ans = 1 + max(max(recur(H+3, A+2, 0), recur(H-5, A-10, 1)), recur(H-20, A+5, 2));
	else
		if( last == 0 )
			ans = 1 + max(recur(H-5, A-10, 1), recur(H-20, A+5, 2));
		else
			if( last == 1 )
				ans = 1 + max(recur(H+3, A+2, 0), recur(H-20, A+5, 2));
			else if( last == 2)
				ans = 1 + max(recur(H+3, A+2, 0), recur(H-5, A-10, 1));

	if( last != -1 )
		dp[H][A][last] = ans;
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int H, A;
		memset(dp, -1, sizeof(dp));
		cin>>H>>A;

		cout<<recur(H,A,-1)-1<<endl;
	}
}