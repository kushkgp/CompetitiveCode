#include <bits/stdc++.h>
#define N 1000001
using namespace std;



int maxsum_subarray(int a[],int n){
	int dp[n],maxdp;
	dp[0]=a[0];
	maxdp=dp[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i]=a[i]+max(0,dp[i-1]);
		if (dp[i]>maxdp)
			maxdp = dp[i];
	}
	return maxdp;
}



int main(){
	int t,a[N],initR;
	string s;
	cin>>t;
	while(t--){
		initR=0;
		cin>>s;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i]=='R'){
				a[i]=-1;
				initR++;
			}
			else a[i]=1;
		}
		cout<<maxsum_subarray(a,s.size())+initR<<endl;
	}
}