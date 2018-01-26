#include <bits/stdc++.h>
using namespace std;

void printmatrix(long int **dp,int n){
	cout<<"matrix:"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%2ld ",dp[i][j] );
		}
		cout<<endl;
	}
	cout<<endl;
}

long int ans(int n,int k){
	long int **dp;
	dp = new long int*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new long int[n+1];
	}
	for(int i = 0; i<=n;i++){
		dp[i][0] = 0;
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = dp[i][j-1];
			if (i-j>=0 && j>=k)
				dp[i][j]+=dp[i-j][j];
		}
	// printmatrix(dp,n+1);
	}
	long int temp = dp[n][n];
	for (int i = 0; i < n+1; ++i)
	{
		free(dp[i]);
	}
	free(dp);
	return temp;
}

int main(){ 
	int t,k,n;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<ans(n,k)<<endl;
	}
}