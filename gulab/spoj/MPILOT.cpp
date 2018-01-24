#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector <pii> vpii;


int ans(const vpii & v, int n){
	int dp[n][n/2+1];
	for (int i = 0; i <= n/2; ++i)
	{
		dp[0][i]=-1;
	}
	dp[0][0] = v[0].second;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= n/2; ++j)
		{
			if((i+1)/2<(j))
				dp[i][j]=-1;
			else{
				dp[i][j]=INT_MAX;
				if(j)
					dp[i][j] = min(dp[i][j],dp[i-1][j-1]+v[i].first);
				if(dp[i-1][j]!=-1)
					dp[i][j] = min(dp[i][j],dp[i-1][j]+v[i].second);
			}
		}
	}
	return dp[n-1][n/2];
}

int main(){
	int n;
	cin>>n;
	vpii v;
	while(n--){
		pii temp;
		cin>>temp.first>>temp.second;
		v.push_back(temp);
	}
	n = v.size();
	cout<<ans(v,n)<<endl;
}