#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector< pii > vpii;

void ans(const vpii & v, int n, int W){
	int dp[n+1][W+1];
	for (int i = 0; i <= W; ++i)
	{
		dp[0][i]=-1;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if(j>=v[i-1].second && dp[i][j-v[i-1].second]!=-1){
				if(dp[i][j]!=-1)
					dp[i][j] = min(dp[i][j],v[i-1].first+dp[i][j-v[i-1].second]);
				else
					dp[i][j] = v[i-1].first+dp[i][j-v[i-1].second];
			}
		}
	}
	if(dp[n][W]==-1)
		cout<<"This is impossible."<<endl;
	else
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[n][W]<<"."<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int e,f;
		cin>>e>>f;
		int n;
		cin>>n;
		vpii v;
		pii temp;
		while(n--) cin>>temp.first>>temp.second, v.push_back(temp);
		n = v.size();
		ans(v,n,f-e);
	}
}