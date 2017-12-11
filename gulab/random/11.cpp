#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int optprofit(int n,int m,int k,int *rc,int *c){
	int x=n*m;
	int dp[n*m][k+1];
	for (int i = 0; i < x; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i < k+1; ++i)
	{
		if (i >= rc[0]+c[0])
			dp[0][i]=p[0];
		else dp[0][i]=0;
	}
	for (int i = 1; i < x; ++i)
	{
		for (int j = 1; j < k+1 ; ++j)
		{
			dp[i][j]=max(dp[i-1][j],j-w[i]>=0?p[i]+dp[i-1][j-w[i]]:0);
		}
	}
	return dp[n-1][W];
}

int main()
{
	int t,*rc,*c;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int c[400],rc[20],p[400];
		for (int i = 0; i < n; ++i)
		{
			cin>>rc[i];
		}		
		for (int i = 0; i < n*m; ++i)
		{
			cin>>c[i];
		}		
		for (int i = 0; i < n*m; ++i)
		{
			cin>>p[i];
		}
	}

	cout<<optprofit(n,m,k,rc,c)<<endl;
	return 0;

}