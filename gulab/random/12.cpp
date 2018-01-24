#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int optprofit(int n,int m,int k,int rc[],int c[],int p[]){
	int x=n*m;
	int dp[n*m+1][k+1];
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 0; j < k+1 ; ++j)
		{
			if(j<c[i]+rc[(i-1)/m]){
				dp[i][j]=-1;
				continue;
			}
			int max=0;
			for (int z = 0; z <= i; ++z)
			{
				int zj=j-c[i];
				if((z-1)/m!=(i-1)/m){
					zj-=rc[(z-1)/m];
				}
				
				if (zj>=0&&dp[z][zj]>=0)
				{
					if (max<dp[z][zj])
					{
						max=dp[z][zj];
					}
				}
			}
			dp[i][j]=p[i]+max;
		}
	}
	int max=0;
	for (int i = 0; i <= x; ++i)
	{
		if (max<dp[i][k])
		{
			max=dp[i][k];
		}
	}
	return max;
}

int main()
{
	int t,*rc,*c;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int c[401],rc[20],p[401];
		for (int i = 0; i < n; ++i)
		{
			cin>>rc[i];
		}		
		for (int i = 1; i <= n*m; ++i)
		{
			cin>>c[i];
		}		
		for (int i = 1; i <= n*m; ++i)
		{
			cin>>p[i];
		}
		// cout<<rc[1]<<endl;
		cout<<optprofit(n,m,k,rc,c,p)<<endl;
	}

	return 0;

}