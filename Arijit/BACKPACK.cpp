#include <bits/stdc++.h>

using namespace std;

long long int dp[65][32005], v[65], c[65], u[65], att[65][2];

int main()
{
	int t = 1;
    cin>>t;
	while(t--)
	{
		memset( dp, 0, sizeof(dp) );
		int n, vmax;
        cin>>vmax>>n;
        memset(att, 0, sizeof(att));

        for( int i = 1; i <= n; i++ )
        {
            cin>>v[i]>>c[i]>>u[i];
            if( u[i] != 0 )
            {
                if( att[u[i]][0]==0)
                    att[u[i]][0] = i;
                else
                    att[u[i]][1] = i;
            }
        }

        for( int i = 1; i <=n; i++ )
        {
            for( int j = 0; j <= vmax; j++ )
            {
                dp[i][j] = dp[i-1][j];
                if( u[i] == 0 )
                {
                    if( j >= v[i] )
                        dp[i][j] = max(dp[i][j], v[i]*c[i] + dp[i-1][j-v[i]]);

                    if( att[i][0]!=0)
                    {
                        if( j >= v[i] + v[att[i][0]])
                            dp[i][j] = max(dp[i][j], v[i]*c[i] + v[att[i][0]]*c[att[i][0]] + dp[i-1][j-v[i] - v[att[i][0]]]);
                    }

                    if( att[i][1] != 0 )
                    {
                        if( j >= v[i] + v[att[i][1]])
                            dp[i][j] = max(dp[i][j], v[i]*c[i] + v[att[i][1]]*c[att[i][1]] + dp[i-1][j-v[i] - v[att[i][1]]]);
                                        
                        if( j >= v[i] + v[att[i][1]] + v[att[i][0]])
                            dp[i][j] = max(dp[i][j], v[i]*c[i] + v[att[i][1]]*c[att[i][1]] + v[att[i][0]]*c[att[i][0]] + dp[i-1][j-v[i] - v[att[i][0]] - v[att[i][1]]]);
                    
                    }
                }
            }
        }

		cout<<dp[n][vmax]<<endl;
    }
  	
}
	