#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int noofways(int s[],int m,int n){
	int dp[m][n+1];
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		dp[i][0]=1;
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if(j-s[i]>=0)
				dp[i][j]+=dp[i][j-s[i]];
			if(i-1>=0)
				dp[i][j]+=dp[i-1][j];
		}
	}
	return dp[m-1][n];
}

int main(){
	int m,n;
	cin>>m>>n;
	int *s;
	s=(int*)malloc(m*sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		cin>>s[i];
	}
	cout<<noofways(s,m,n)<<endl;
}