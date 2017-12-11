#include <bits/stdc++.h>
using namespace std;

int ans(const string & a, const string & b, int m, int n,int x){
	int dp[m+1][n+1];
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			if(i&&j) dp[i][j] = min(abs(a[i-1]-b[j-1])+dp[i-1][j-1],x+min(dp[i-1][j],dp[i][j-1]));
			else{
				if(!i) dp[i][j] = j*x;
				else dp[i][j] = i*x;
			}
		}
	}
	return dp[m][n];
}

int main(){
	string s1,s2;
	int x;
	cin>>s1>>s2>>x;
	cout<<ans(s1,s2,s1.length(),s2.length(),x)<<endl;
}