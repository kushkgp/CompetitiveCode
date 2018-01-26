#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t,A;
	// int a[100],dp[10001];
	cin>>t;
	while(t--){
		cin>>A>>n;
		//cout<<"jh "<<dp[0]<<endl;
		int a[n];
		int *dp =new int[A+1];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		dp[0]=0;
		int mindp;
		for (int i = 1; i <= A; ++i)
		{
			mindp=100000;
			for (int j = 0; j < n; ++j)
			{
				if(i-a[j]>=0)
					if(mindp>dp[i-a[j]]){
					mindp = dp[i-a[j]];
				}
			}
			// if(!i)
			// cout<<i<<endl;
			dp[i] = 1+mindp;
		}

		// cout << endl;
		// for(int i = 0 ; i <= A ; i++)
		// 	cout << dp[i] << " ";
		// cout << endl;

		if(dp[A]<100000)
			cout<<dp[A]<<endl;
		else
			cout<<"No solution"<<endl;
		delete dp;
	}
	return 0;
}