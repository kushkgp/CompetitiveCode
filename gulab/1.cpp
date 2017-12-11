#include <bits/stdc++.h>
using namespace std;

int min_sum(int *a,int n,int k){
	int dp[n+1][k+1];
	dp[0][0]=0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			dp[i][j]=-1;
			int x=INT_MAX;
			if (i>0)
			{
				for (int m = 1; m <= j; ++m)
				{
					if(dp[i-1][j-m]!=-1&&a[m-1]!=-1){
						if(x>dp[i-1][j-m]+a[m-1])
							x=dp[i-1][j-m]+a[m-1];
					}
				}
			}
			if(x==INT_MAX){
				dp[i][j]=-1;
			}
			else dp[i][j]=x;
			if(j==0)
				dp[i][0]=0;
		}
	}
	// dp[i][j] = min(possible(dp[i-1][j-k]+a[k-1]))
	return dp[n][k];
}

int main(){
	int t,n,k,*a;
	cin>>t;
	while(t){
		cin>>n>>k;
		a=new int[k];
		for (int i = 0; i < k; ++i)
		{
			cin>>a[i];
		}
		cout<<min_sum(a,n,k)<<endl;
		t--;
		delete a;
	}

	return 0;
}