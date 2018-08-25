#include <bits/stdc++.h>

using namespace std;

long long int dp[1005][1005] ;
int k;
string x, y;

int main()
{
	int t = 1;
	while(t)
	{
		cin>>k;
		memseqxat( dp, 0, sizeof(dp) );
		if( k == 0 )
			break;
        
        cin>>x>>y;
        int c;
    	for(int i=0; i<=x.length(); i++)
    	{
    		for(int j=0; j<=y.length(); j++)
    		{
        		dp[i][j] = 0;
        		if(i==0 || j==0)
            		continue;
        		c = 1;
        		while(i-c>=0 && j-c>=0 && x[i-c]==y[j-c])
        		{
            		if(c>=k)
                		dp[i][j] = max(dp[i][j], c+dp[i-c][j-c]);
            		c++;
        		}
        		dp[i][j] = max(dp[i][j], dp[i-1][j]);
        		dp[i][j] = max(dp[i][j], dp[i][j-1]);
    		}
		}
		cout<<dp[x.length()][y.length()]<<endl;
    }
  	
}
	