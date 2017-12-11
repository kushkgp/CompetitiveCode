#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int wordwrap(int *wlen,int n){
	int dp[n+1],f[n+1];
	dp[0]=0;
	for (int i = 1; i < n+1; ++i)
	{
		int min = INT_MAX;
		int sum=wlen[i-1];
		for (int k = i-1; k >= 0; --k)
		{
			if(sum>15)
				break;
			int x=(15-sum);
			x=x*x*x;
			x+=dp[k];
			if (min>x){
				min=x;
				f[i]=k;
			}
			if (k)
				sum+=(1+wlen[k-1]);
		}
		dp[i]=min;
	}
	for (int i = n; i > 0 ; i=f[i])
	{
		cout<<f[i]+1<<" to "<<i<<endl;
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int *wlen=(int*)malloc(n*sizeof(int));
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		wlen[i]=s.length();
	}
	cout<<wordwrap(wlen,n)<<endl;
}