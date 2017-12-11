#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int ans(const vi &w, const vi& v, int s, int n){
	int dp[n+1][s+1];
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <=s ; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if(w[i-1]<=j){
				dp[i][j] = max(dp[i][j],dp[i-1][j-w[i-1]]+v[i-1]);
			}
		}
	}
	return dp[n][s];
}

int main(){
	int s,n;
	cin>>s>>n;
	vi w,v;
	while(n--){
		int t;
		cin>>t;
		w.push_back(t);
		cin>>t;
		v.push_back(t);
	}
	n=v.size();
	cout<<ans(w,v,s,n)<<endl;
}