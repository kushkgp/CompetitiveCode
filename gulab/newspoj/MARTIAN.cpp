#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;

int ans(vvi & Y, vvi & B, int n, int m){
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if(j)
				Y[i][j]+=Y[i][j-1];
			if(i)
				B[i][j]+=B[i-1][j];
		}
	// cout<<"hello"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int y = Y[i][j];
			int b = B[i][j];
			if(i)
				y+=dp[i-1][j];
			if(j)
				b+=dp[i][j-1];
			dp[i][j]=max(y,b);
		}
	}
	return dp[n-1][m-1];
}

int main(){
	int n,m;
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n>>m;
	while(n&&m){
		vvi Y,B;
		Y.resize(n,vi(m,0));
		B.resize(n,vi(m,0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>Y[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>B[i][j];
		cout<<ans(Y,B,n,m)<<endl;
		cin>>n>>m;
	}
	return 0;
}