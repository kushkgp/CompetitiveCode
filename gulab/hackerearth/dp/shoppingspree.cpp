#include <bits/stdc++.h>
#define rem 1000000007
using namespace std;


int ans(int n,int k){
	int dp[k+1];
	dp[0]=1;
	for (int i = 0; i <n ; ++i)
	{
		for (int j = 1; j <=k; ++j)
		{
			if(j==0){
				dp[j]=1;
				continue;
			}
			if(i==0)
				dp[j] = 0;
			dp[j] += dp[j-1];
			dp[j] %= rem;
		}
	}
	int sum = 0;
	for (int i = 1; i <= k; ++i)
	{
		sum+=dp[i];
		sum%=rem;
	}
	return sum;
}


int main(){
	int n,k;
	cin>>n>>k;
	cout<<ans(n,k)<<endl;
	return 0;
}