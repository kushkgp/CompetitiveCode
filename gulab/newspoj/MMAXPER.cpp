#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,prea,preb,n,dp[2],predp[2];
	cin>>n;
	n--;
	cin>>a>>b;
	dp[0]=a;
	dp[1]=b;
	while(n--){
		predp[0]=dp[0];
		predp[1]=dp[1];
		prea = a;
		preb = b;
		cin>>a>>b;
		dp[0] = max(predp[0]+abs(preb-b)+a,predp[1]+abs(prea-b)+a);
		dp[1] = max(predp[0]+abs(preb-a)+b,predp[1]+abs(prea-a)+b);
	}
	cout<<max(dp[0],dp[1])<<endl;
	return 0;
}