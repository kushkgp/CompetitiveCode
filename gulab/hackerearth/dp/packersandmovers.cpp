#include <bits/stdc++.h>
using namespace std;


int ans(int m,int p,int *a){
	int dp[p+1][m+1];
	for (int i = 0; i <m; ++i)
		dp[0][i] = 0;

	for (int i = 1; i <= p; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			dp[i][j]=INT_MAX;
			if(j){
				dp[i][j] = min(dp[i][j],dp[i][j-1]);
				int temp=0,tempmax;
				for (int k = 1; k <= i; ++k)
				{
					temp+=a[i-k];
					// printf("%d\n",temp);
					tempmax=max(dp[i-k][j-1],temp);
					dp[i][j] = min(tempmax,dp[i][j]);
				}
			}
		}
	}
	return dp[p][m];
}


int main(){
	int m,p;
	int *a;
	cin>>m>>p;
	a = new int[p];
	for (int i = 0; i < p; ++i)
		cin>>a[i];
	cout<<ans(m,p,a)<<endl;
}