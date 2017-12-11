#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ans(int n){
	ll dp[6][n+1];
	int a[5] = {2,3,6,7,8};
	for (int i = 0; i <= n; ++i)
	{
		dp[0][i] = 0;
	}
	dp[0][0]=1;
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=a[i-1])
				dp[i][j]+=dp[i][j-a[i-1]];
		}
	}
	return dp[5][n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans(n)<<endl;
	}
}