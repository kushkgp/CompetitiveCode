#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int compare(const int &a, const int &b){
	if(a==b) return 0;
	return 1;
}

int ans(const vi &v, int n){
	int dp[n][n];
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			int j = i+k;
			if(k==1)
				dp[i][j] = max(v[i],v[j]);
			else{
				int dp1,dp2;
				dp1 = v[i];
				dp1+= v[i+1]>=v[j]?dp[i+2][j]:dp[i+1][j-1];
				dp2 = v[j];
				dp2+= v[i]>=v[j-1]?dp[i+1][j-1]:dp[i][j-2];
				dp[i][j] = max(dp1,dp2);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum+=v[i];
	return (dp[0][n-1]<<1)-sum;
}

int main(){
	int n;
	cin>>n;
	int count=1;
	while(n){
		vi v;
		v.resize(n,0);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",count++,ans(v,n));
		cin>>n;
	}
}