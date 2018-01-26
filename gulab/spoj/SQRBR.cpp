#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
ll ans(const vi & v,int n){
	ll dp[(n<<1)+1][n+1];
	for (int i = 0; i <= n; ++i)
		dp[0][i]=0;
	dp[0][0] = 1;
	// n<=1;
	for (int i = 1; i <= n<<1; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] = 0;
			if(j){
				dp[i][j]+=dp[i-1][j-1];
			}
			if(j<n){
				if(!v[i-1])
					dp[i][j]+=dp[i-1][j+1];
			}
		}
	}
	return dp[n<<1][0];
}

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vi v,a;
		a.resize(n<<1,0);
		v.resize(k,0);
		for (int i = 0; i < k; ++i){
			cin>>v[i];
			a[--v[i]]=1;
			// cout<<i<<" ";
		}
		// cout<<endl;

		cout<<ans(a,n)<<endl;
	}
}