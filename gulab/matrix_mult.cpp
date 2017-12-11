#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;

int minmatrix(int p[],int n){
	int dp[n+1][n+1];
	for (int i = 0; i <=n; ++i)
	{
		dp[i][i]=0;
		dp[i][i+1]=0;
	}
	for (int i = n-2; i >=0; --i)
	{
		for (int j = i+2; j <=n; ++j)
		{
			int min = INT_MAX;
			for (int k = i+1; k < j; ++k)
			{
				int x = dp[i][k]+dp[k][j]+p[i]*p[j]*p[k];
				if (min>x)
					min=x;
			}
			dp[i][j]=min;
		}
	}
	//cout<<dp[0][2]<<endl;
	return dp[0][n];
}
int main(){
	int n,*p;
	cin>>n;
	p=(int*)malloc((n+1)*sizeof(int));
	for (int i = 0; i < n+1; ++i)
	{
		cin>>p[i];
		cout<<p[i]<<endl;
	}
	cout<<minmatrix(p,n)<<endl;
	return 0;
}