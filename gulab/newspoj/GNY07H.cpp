#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int dp[1000],a[1000],b[1000];
int main(){
	int t;
	cin>>t;
	for (int i = 0; i < 1000; ++i)
	{
		dp[i] = -1;
	}
	dp[0] = 1;
	dp[1] = 1;
	a[0] = 0;
	a[1] = 1;
	b[0] = 0;
	b[1] = 1;
	int s = 2;
	int index = 1;
	while(t--){
		int n;
		cin>>n;
		if(n>=s){
			for (int i = s; i <= n; ++i)
			{
				a[i] = dp[i-1]+a[i-2];
				b[i] = dp[i-1]+b[i-1];
				dp[i] = dp[i-1]+dp[i-2]+a[i-1]+2*b[i-1];
			}
			s=n+1;
		}
		cout<<index++<<" "<<dp[n]<<endl;
	}
	return 0;
}