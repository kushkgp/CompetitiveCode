#include <bits/stdc++.h>
using namespace std;
int ans(const string & s1, const string & s2){
	int prev[s2.length()][26];
	int prevarr[26];
	int m = s1.length();
	int n = s2.length();
	memset(prevarr,-1,sizeof(prevarr));
	for (int i = 0; i < n; ++i)
	{
		prevarr[s2[i]-'a'] = i;
		for (int j = 0; j < 26; ++j)
		{
			prev[i][j] = prevarr[j];
		}
	}
	int dp[s1.length()+1][s2.length()+1];
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if(!i){
				dp[i][j]=-1;
				continue;
			}
			if(!j){
				dp[i][j]=1;
				continue;
			}
			int x = prev[j-1][s1[i-1]-'a'];
			if(x==-1)
				dp[i][j]=1;
			else{
				dp[i][j] = dp[i-1][j];
				if(dp[i-1][x]!=-1){
					if(dp[i][j]==-1)
						dp[i][j] = 1+dp[i-1][x];
					else
						dp[i][j] = min(1+dp[i-1][x],dp[i][j]);
				}
			}
		}
	}
	return dp[m][n];
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<ans(s1,s2)<<endl;
}