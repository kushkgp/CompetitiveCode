// spoj bat1
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int optprofit(int n,int m,int k,int rc[],int c[],int p[]){
	int x=n*m;
	int dp[x+1][k+1],last[x+1][k+1];
	memset(dp,0,sizeof(dp));
	memset(last,0,sizeof(dp));
	for (int i = 1; i <= x; i++)
   {
       for (int j = 0; j <= k; j++)
       {
            dp[i][j]=dp[i-1][j];
            last[i][j]=last[i-1][j];
            if (j<c[i] + rc[(i-1)/m])
            	continue;
           		
   			if (dp[i][j]<p[i] + dp[i-1-(i-1)%m][j-c[i]-rc[(i-1)/m]])
   			{
   				dp[i][j]=p[i] + dp[i-1-(i-1)%m][j-c[i]-rc[(i-1)/m]];
   				last[i][j]=i;
   			}
       		if((last[i][j-c[i]]-1)/m==(i-1)/m){
       			if (dp[i][j]<p[i] + dp[i][j-c[i]])
       			{
       				dp[i][j]=p[i] + dp[i][j-c[i]];
       				last[i][j]=i;
       			}
        	}

       	}
    }
	
	return dp[x][k];
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int c[401],rc[20],p[401];
		for (int i = 0; i < n; ++i)
			cin>>rc[i];	
		for (int i = 1; i <= n*m; ++i)
			cin>>c[i];
		for (int i = 1; i <= n*m; ++i)
			cin>>p[i];
		// cout<<rc[1]<<endl;
		cout<<optprofit(n,m,k,rc,c,p)<<endl;
	}

	return 0;

}