#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int ans(const vi& a, int n){
	ll dp[n+1][n];
	for (int i = 0; i < n; ++i)
	{
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if(j){
				dp[i][j] += (a[i-1]*dp[i-1][j-1]);
				if(j>1)
					dp[i][j]+= ((((a[i-1]*(a[i-1]-1))/2))*dp[i-1][j-2]);
			}
			dp[i][j]%=MOD;
		}
	}
	return dp[n][n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		vi v;
		int temp;
		cin>>n;
		while(n--) cin>>temp, v.push_back(temp);
		n=v.size();
		cout<<ans(v,n)<<endl;
	}
}