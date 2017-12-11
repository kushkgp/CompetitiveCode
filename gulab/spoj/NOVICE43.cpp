#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[11][26];

void make_ans(){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i < 11; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{	
			dp[i][j]=(j+1)*dp[i-1][j];
			if(j)
				dp[i][j]+= dp[i-1][j-1];
		}
	}
}

int ans(int n){
	int retsum=0;
	for (int i = 0; i < 26; ++i)
	{
		// if(dp[n-1][i])
		// 	cout<<i<<" "<<dp[n-1][i]<<endl;
		retsum+=dp[n-1][i];
	}
	return retsum;
}

int main(){
	int t;
	cin>>t;
	make_ans();
	while(t--){
		int n;
		cin>>n;
		cout<<ans(n)<<endl;
	}
}