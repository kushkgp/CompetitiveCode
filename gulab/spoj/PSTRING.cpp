#include <bits/stdc++.h>
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;

int main(){
	string x, y;
	cin>>x>>y;
	int m = x.length(), n = y.length();
	vv<int> dp(m+1, v<int>(n+1, 0));
	for(int i = 0; i <= m; i++){
		dp[i][0] = -1;
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <=n; j++){
			if(x[i-1] == y[j-1])
				dp[i][j] = max(dp[i-1][j-1]==-1?-1:dp[i-1][j-1]+1, dp[i-1][j]);
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][n]+1);
		}
	}
	cout<<m - dp[m][n]<<endl;
}