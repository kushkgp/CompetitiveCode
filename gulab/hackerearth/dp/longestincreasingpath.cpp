#include <bits/stdc++.h>
using namespace std;

int ans(int **a,int m,int n){
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = m-1; j >= 0; --j)
		{
			dp[i][j]=1;
			if(i!=n-1 && a[i][j]<a[i+1][j])
				dp[i][j] = max(dp[i][j],dp[i+1][j]+1);
			if(j!=m-1 && a[i][j]<a[i][j+1])
				dp[i][j] = max(dp[i][j],dp[i][j+1]+1);
	// cout<<"ji"<<endl;
		}
	}
	return dp[0][0];
}


int main(){
	int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int **a = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			a[i] = new int[m];
			for (int j = 0; j < m; ++j)
			{
				cin>>a[i][j];
			}
		}
		cout<<ans(a,m,n)<<endl;
		for (int i = 0; i < n; ++i)
		{
			delete a[i];
		}
		delete a;
	}
}