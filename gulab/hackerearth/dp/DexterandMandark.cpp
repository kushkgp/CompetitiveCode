#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

int noofways(int n,int m){
	int dp[n+1],prevdp;
	// memset(dp,sizeof(dp),0);
	// cout<<"dp :"<<endl;
	for (int i = 0; i <= n; ++i)
	{
		dp[i]=0;
		// cout<<dp[i]<<" ";
	}
	dp[1]=1;
	// cout<<endl;
	for (int i = 1; i < n; ++i)
	{
		prevdp = dp[0];
		for (int j = 0; j <= n; ++j)
		{
			int temp = dp[j];
			dp[j]=0;
			if(j){
				dp[j]+=prevdp;
				dp[j]%=N;
			}
			if(j+m<=n){
				dp[j]+=dp[j+m];
				dp[j]%=N;
			}
			prevdp = temp;
		}
	}
	int sum = 0;
	for (int i = 0; i <= n; ++i)
	{	if(m!=1||i!=0){
			sum+=dp[i];
			sum%=N;
		}
	}

	return sum;
}

int main(){
	int n,m,*a;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<noofways(n,m)<<endl;
	}
}