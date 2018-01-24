#include <bits/stdc++.h>
using namespace std;
typedef vector< int > vi;

int ans(const vi & a, int n, int m){
	int dp[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if(a[i]<a[j])
				dp[i] = max(dp[i],dp[j]+1);
			else if(j==m)
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int retmax = 1;
	for (int i = 0; i < n; ++i)
	{
		retmax = max(retmax,dp[i]);
	}
	return retmax;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vi v;
		int temp;
		while(n--) cin>>temp, v.push_back(temp);
		n = v.size();
		cout<<ans(v,n,m)<<endl;
	}
}