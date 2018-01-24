#include <bits/stdc++.h>
using namespace std;


long int ans(int n){
	long int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <=i; ++j)
		{
			if(j)
				dp[i][j]+=dp[i][j-1];
			if(i>j)
				dp[i][j]+=dp[i-1][j];
		}
	}
	return dp[n][n];
}


int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<ans(n)<<endl;
	}
}