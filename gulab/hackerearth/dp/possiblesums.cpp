#include <bits/stdc++.h>
using namespace std;


int ans(int *a,int n,int maxsum){
	bool dp[maxsum+1];
	fill(dp,dp+maxsum+1,false);
	dp[0]=1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = maxsum; j > 0; --j)
		{
			if(j>=a[i])
				dp[j]|=dp[j-a[i]];
		}
	}
	int sum =0;
	for (int i = 0; i <= maxsum; ++i)
	{
		if(dp[i]){
		// cout<<i<<endl;
			sum++;
		}
	}
	return sum;
}

int main(){
	int t;
	int n;
	int *a;
	cin>>t;
	while(t--){
		cin>>n;
		a = new int[n];
		int maxsum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			maxsum+=a[i];
		}
		cout<<ans(a,n,maxsum)<<endl;
		delete a;
	}
}