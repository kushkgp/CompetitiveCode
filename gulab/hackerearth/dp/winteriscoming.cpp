#include <bits/stdc++.h>
using namespace std;

void indicesofsum(int *a,int n){
	int l,r,d=INT_MAX,dp[n],sum=0;
	for (int i = 0; i < n; ++i)
		dp[i]=-2;
	dp[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		sum=(sum+a[i])%n;
		if(dp[sum]!=-2){
			if(i-dp[sum]<d){
				l = dp[sum]+2;
				r = i+1;
				d = i-dp[sum];
				if(!d)
					break;
			}
		}
		dp[sum]=i;
	}
	cout<<l<<" "<<r<<endl;
}


int main(){
	int t;
	int n,*a;
	cin>>t;
	while(t--){
		cin>>n;
		a = new int[n];

		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			// a[i1]%=n;
		}
		indicesofsum(a,n);
		delete a;
	}
}