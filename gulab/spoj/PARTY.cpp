#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector <pii> vpii;

int ans(const vpii & v, int n, int budget){
	int dp[n][budget+1];
	for (int i = 0; i <=budget; ++i)
		dp[0][i]=-1; 
	dp[0][v[0].first] = v[0].second;
	dp[0][0]=0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= budget; ++j)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=v[i].first && dp[i-1][j-v[i].first]!=-1)
				dp[i][j] = max(dp[i][j],dp[i-1][j-v[i].first] + v[i].second);
		}
	}
	int retans = 0,amount = 0;
	for (int i = 0; i <= budget; ++i)
		if(retans<dp[n-1][i]) retans =dp[n-1][i], amount=i;
	cout<<amount<<" ";
	return retans;
}

int main(){
	while(1){
		int budget,n;
		cin>>budget>>n;
		if(!budget && !n)
			break;
		vpii v;
		pii temp;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp.first>>temp.second;
			v.push_back(temp);
		}
		cout<<ans(v,n,budget)<<endl;
	}
	return 0;
}