#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int minjump(int *a,int n){
	int dp[n];
	dp[0]=0;
	for (int i = 1; i < n; ++i)
	{
		int min = INT_MAX;
		for (int j = 0; j < i; ++j)
		{
			if(i-j<=a[j])
				if (min > 1+dp[j])
					min=1+dp[j];
		}
		dp[i]=min;
	}
	return dp[n-1];
}

int main(){
	int n;
	cin>>n;
	int *a=(int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<minjump(a,n)<<endl;
}