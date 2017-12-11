#include <iostream>
#include <limits.h>
#include <cstring>
#include <cstdlib>
using namespace std;

int min(int x,int y,int z){
	return min(min(x,y),z);
}

int mincost(int **a,int m,int n){
	int dp[m+2][n+2];
	memset(dp,50,sizeof(dp));
	dp[0][0]=0;
	for (int i = 1; i < m+2; ++i)
	{
		for (int j = 1; j < n+2; ++j)
		{	
			dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+a[i-1][j-1];
		}
	}
	return dp[m+1][n+1];
}
int main(){
	int m,n;
	cin>>m>>n;
	int **a;
	a=(int **) malloc((m+1)*sizeof(int*));
	for (int i = 0; i <= m; ++i)
	{
		a[i] = (int *)malloc((n+1)*sizeof(int));
		for (int j = 0; j <= n; ++j)
		{
			cin>>a[i][j];
		}
	}
	cout<<mincost(a,m,n)<<endl;
	return 0;
}