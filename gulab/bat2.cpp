#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct sturcture
{
	int val;
	int index;
}abc;

bool lessthan(abc & a,abc & b){
	return (a.val<b.val);
}

int maxincdec_length(int *a, int n){
	int dp[n+1][100][100];
	memset(dp,sizeof(dp),0);
	// cout<<a[0]<<" "<<a[5]<<endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			for (int k = 0; k < 100; ++k)
			{
	// cout<<i<<" "<<j<<"hello"<< k<<endl;
				int max = dp[i-1][j][k];
				if (a[i-1]<j && max<1+dp[i-1][a[i-1]][k])
					max = 1+dp[i-1][a[i-1]][k];
				if (a[i-1]>k && max<1+dp[i-1][j][a[i-1]])
					max = 1+dp[i-1][j][a[i-1]];
				dp[i][j][k] = max;
			}
		}
	}
	return dp[n][99][0];
}




int main(){
	int t,n;
	abc *a;
	cin>>t;
	while(t--){
		cin>>n;
		a = new abc[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].val;
			a[i].index = i;
		}
		
		sort(a,a+n,lessthan);
		int b[n];
		for (int i = 0; i < n; ++i)
		{
			b[a[i].index] = i;
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout<<b[i]<<" ";
		// }
		// cout<<endl;
		cout<<maxincdec_length(b,n)<<endl;;
		delete a;
	}
}