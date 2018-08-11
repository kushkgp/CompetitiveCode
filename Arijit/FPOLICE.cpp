#include <bits/stdc++.h>

using namespace std;

int risk[105][105], time1[105][105], dp[105][255];
# define INF 1e9

int solve(int nn,int t, int size)
{
    if(nn==0 && t==0)
        return 0;
    if(t<0)
        return INF;
    if(dp[nn][t]!=-1)
        return dp[nn][t];
    dp[nn][t]=solve(nn,t-1,size);
    for(int i=0;i<size;i++)
    {
        if(t>=time1[i][nn])
            dp[nn][t]=min(dp[nn][t],solve(i,t-time1[i][nn],size)+risk[i][nn]);
    }
    return dp[nn][t];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,temp;
		cin>>n>>k;

		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				cin>>temp;
				time1[i][j] = temp;
			}
		}

		memset( dp, -1, sizeof(dp) );
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				cin>>temp;
				risk[i][j] = temp;
			}
		}

		dp[0][0] = 1;
		int ans = solve(n-1,k,n);
		if(ans==INF)
        {
            cout<<"-1"<<endl;
            continue;
        }
		cout<<ans<<" ";

		for( int i = 0; i < k; i++ )
		{
			if(dp[n-1][i]==ans)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}