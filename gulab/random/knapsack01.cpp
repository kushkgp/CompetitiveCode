#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int optprofit(int n,int W,int *w,int *p){
	int dp[n][W+1];
	for (int i = 0; i < n; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i < W+1; ++i)
	{
		if (i >= w[0])
			dp[0][i]=p[0];
		else dp[0][i]=0;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < W+1 ; ++j)
		{
			dp[i][j]=max(dp[i-1][j],j-w[i]>=0?p[i]+dp[i-1][j-w[i]]:0);
		}
	}
	return dp[n-1][W];
}

int main()
{
	int n,W,*w,*p;
	cin>>n>>W;
	w=(int*)malloc(n*sizeof(int));
	p=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		cin>>w[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	cout<<optprofit(n,W,w,p)<<endl;
	return 0;
}
