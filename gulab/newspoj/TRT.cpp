#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;

ll ans(const vi &v, int n){
	ll dp[n][n];
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			int sum = v[i+k];
			if(i)
				sum-=v[i-1];
			dp[i][i+k] = sum;
			if(k)
				dp[i][i+k]+=max(dp[i+1][i+k],dp[i][i+k-1]);
		}
	}
	return dp[0][n-1];
}

int main(){
	int n;
	cin>>n;
	vi v;
	v.resize(n,0);
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	for (int i = 1; i<n; ++i)
		v[i]+=v[i-1];
	cout<<ans(v,n)<<endl;
}