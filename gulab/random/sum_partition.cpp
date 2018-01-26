#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int partition(int *a,int n){
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=a[i];
	}
	if(sum%2==1)
		return 0;
	int dp[n+1][sum+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 0; j <=sum ; ++j)
		{
			if(j==0)
				dp[i][0]=1;
			else {
				dp[i][j]=dp[i-1][j];
				if(j>=a[i-1])
					dp[i][j]=dp[i][j]||dp[i-1][j-a[i-1]];
			}
		}
	}

	int x=0;
	for (int i = 1; i < n+1; ++i)
	{
		x=x||dp[i][sum/2];
	}
	return x;
}

int main(){
	int n,*a;
	cin>>n;
	a=(int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<partition(a,n)<<endl;
}