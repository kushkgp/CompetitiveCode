#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int maxprofit(int n,int *p){
	int dp[n+1];
	for (int i = 1; i <= n; ++i)
	{
		int max=p[i];
		for (int k = 1; k <= i/2; ++k)
		{
			int x=dp[k]+dp[i-k];
			if(max<x)
				max=x;
		}
		dp[i]=max;
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int *p;
	p=(int *)malloc((n+1)*sizeof(int));
	for (int i = 1; i < n+1; ++i)
	{
		cin>>p[i];
	}
	cout<<maxprofit(n,p)<<endl;
	return 0;
}