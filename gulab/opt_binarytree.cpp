#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int optbintree(int *a,int n){
	int s[n+2][n+2],dp[n+2][n+2];

	for (int i = 1; i <= n; ++i)
	{
		s[i][i]=a[i];
		dp[i][i]=a[i];
		dp[i][i-1]=0;
		s[i][i-1]=0;
	}
	dp[n+1][n]=0;
	s[n+1][n]=0;
	for (int i = n; i>=1; --i)
	{
		for (int j = i+1 ; j <= n; ++j)
		{
			int min=INT_MAX;
			s[i][j]=s[i][j-1]+a[j];
			int x;
			for (int k = i; k <= j; ++k)
			{
				x=dp[i][k-1]+s[i][k-1]+a[k]+dp[k+1][j]+s[k+1][j];
				if(min>x)
					min=x;
			}
			dp[i][j]=min;
		}
	}
	return dp[1][n];
}

int main(){
	int n;
	cin>>n;
	int *a =(int *)malloc((n+1)*sizeof(int));
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	cout<<optbintree(a,n)<<endl;
}