#include <bits/stdc++.h>
using namespace std;
typedef struct cylinder{
	int o,n,w;
} cyl;

typedef vector< cyl > vc;

int ans(const vc & v, int n, int o2, int n2){
	int dp[n+1][80][80];
	// memset(dp[0],INT_MAX,sizeof(dp[0]));
	for (int i = 0; i <= 79; ++i)
	{
		for (int j = 0; j <= 79; ++j)
		{
			dp[0][i][j] = INT_MAX;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= 79; ++j)
		{
			for (int k = 0; k <= 79; ++k)
			{
				dp[i][j][k] = dp[i-1][j][k];
				int x = j-v[i-1].o>0? j-v[i-1].o:0;
 				int y = k-v[i-1].n>0? k-v[i-1].n:0;
 				if(dp[i-1][x][y]!=INT_MAX)
 					dp[i][j][k] = min(dp[i][j][k],dp[i-1][x][y]+v[i-1].w);
			}
		}
	}
	return dp[n][o2][n2];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int o,n2;
		cin>>o>>n2;
		int n;
		cin>>n;
		cyl temp;
		vc v;
		while(n--) cin>>temp.o>>temp.n>>temp.w, v.push_back(temp);
		n=v.size();
		cout<<ans(v,n,o,n2)<<endl;
	}
}