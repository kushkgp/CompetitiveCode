#include <bits/stdc++.h>
#define sum 225
using namespace std;

int ans(string str,int n){
	int dp[n+1][sum+1];
	for (int i = 0; i <= n; ++i)
	{
		char c = str[i-1];
		int s=atoi(&c),k=1;
		// cout<<s<<endl;
		int x=0;
		for (int j = 0; j <= sum; ++j)
		{
			if(i==0){
				dp[i][j]=1;
				continue;
			}
			if(!x){
				if(j)
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=0;
			}
			// if(i==2&&j==2)
			// 	cout<<endl<<dp[i][j]<<endl;
			if(k <= i && s==j){
				dp[i][j]+=dp[i-k][j];
				c=str[i-k-1];
				s+=atoi(&c);
				// cout<<"s="<<i<<"  "<<j<<" "<<k<<endl;
				k++;
				x=0;
				if(c=='0'){
					j--;
					x=1;
				}
			}
		}
		// cout<<"  "<<dp[i][2]<<endl;
	}
	return dp[n][sum];
}

int main(){
	string s;
	cin>>s;
	int x=1;
	while(s!="bye"){
		cout<<x<<". "<<ans(s,s.length())<<endl;
		cin>>s;
		x++;
	}
}