#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll ans(const string &s1, const string & s2, const string & s3){
	const int l1 = s1.length();
	const int l2 = s2.length();
	const int l3 = s3.length();
	ll dp[l1+1][l2+1][l3+1];
	memset(dp,0,sizeof(dp));
	// dp[0][0][0] = 1;
	for (int i = 0; i <=l1 ; ++i)
	{
		for (int j = 0; j <= l2; ++j)
		{
			for (int k = 0; k <= l3; ++k)
			{
				if(!k){
					dp[i][j][0] = 1;
					continue;
				}
				if(i&&j)
					dp[i][j][k]+=dp[i-1][j-1][k];
				else{
					if(i)
						dp[i][j][k]+=dp[i-1][j][k];
					else if(j)
						dp[i][j][k]+=dp[i][j-1][k];
				}
				if(i){
					if(s1[i-1]==s3[k-1])
						dp[i][j][k]+=dp[i-1][j][k-1];
				}
				if(j){
					if(s2[j-1]==s3[k-1])
						dp[i][j][k]+=dp[i][j-1][k-1];
				}
			}
		}
	}
	return dp[2][1][2];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		cout<<ans(s1,s2,s3)<<endl;
	}
}