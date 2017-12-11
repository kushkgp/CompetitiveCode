#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull ans(int n){
	ull dp[n+1],a[n+1];
	dp[0] = 1;
	dp[1] = 0;
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		a[i] = dp[i-1]+a[i-2];
		dp[i] = dp[i-2]+2*a[i-1];
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	while(n!=-1){
		cout<<ans(n)<<endl;
		cin>>n;
	}
	return 0;
}