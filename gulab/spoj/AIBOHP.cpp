#include <bits/stdc++.h>
using namespace std;

int ans(const string & s1, const string & s2){
	int dp[s1.length()+1][s2.length()+1];
	memset(dp,1,sizeof(dp));
	// cout<<dp[0][1]<<endl;
	for (int i = 0; i <= s1.length(); ++i)
	{
		for (int j = 0; j <= s2.length(); ++j)
		{
			if(!i&&!j) { dp[0][0]=0; continue;}
			if(i&&j&&s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else{
				if(i)
					dp[i][j] = min(dp[i][j],1+dp[i-1][j]);
				if(j){
					dp[i][j] = min(dp[i][j],1+dp[i][j-1]);
					// if(i==0&&j==1) cout<<dp[i][j-1]<<endl;
				}
			}
		}
	}
	return dp[s1.length()][s2.length()]>>1;
}

int main(){
	int t;
	cin>>t;
	char str[7000];
	fgets(str,7000,stdin);
	while(t--){
		fgets(str,7000,stdin);
		if(str[strlen(str)-1]=='\n')
			str[strlen(str)-1] = '\0';
		string s(str);
		string s2 = s;
		reverse(s2.begin(),s2.end());
		cout<<ans(s,s2)<<endl;
	}
}