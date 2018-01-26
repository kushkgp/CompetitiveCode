#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;

int lcs(const vi & a, const vi & b, int m, int n){
	int dp[m+1][n+1];
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j<=n; ++j)
		{
			if(i && j && a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else {
				dp[i][j] = 0;
				if(i)
					dp[i][j] = max(dp[i][j],dp[i-1][j]);
				if(j)
					dp[i][j] = max(dp[i][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main(){
	int t;
	cin>>t;
	int temp=1;
	
	while(t--){
		int minlcs = INT_MIN;
		vi agness;
		cin>>temp;
		while(temp) agness.push_back(temp),cin>>temp;
		cin>>temp;
		while(temp){
			vi tom;
			tom.push_back(temp);
			while(temp) tom.push_back(temp),cin>>temp;
			minlcs = max(minlcs,lcs(agness,tom,agness.size(),tom.size()));
			cin>>temp;
		}
		cout<<minlcs<<endl;
	}
	return 0;
}