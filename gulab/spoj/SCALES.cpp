#include <bits/stdc++.h>
using namespace std;

int ans(int l, int n, int d){
	int dp[2],pdp[2];
	char c;
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	dp[1] = 0;
	char s[100];
	fgets(s,100,stdin);
	while(l--){
		scanf("%c",&c);
		// cout<<c<<" ";
		pdp[0] = dp[0];
		pdp[1] = dp[1];
		if(c=='0'){
			dp[0] = pdp[1]+pdp[0];
			dp[1] = pdp[1];
		}
		else{
			dp[0] = pdp[0];
			dp[1] = pdp[0]+pdp[1];
		}
		// if(l==2)
		// 	break;
	}
	cout<<endl;
	return dp[0];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,d;
		cin>>n>>l>>d;
		cout<<ans(l,n,d)<<endl;
	}
}