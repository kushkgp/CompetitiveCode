#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector< pii > vpii;

float ans(const vpii & v, int n, int d, int m){
	float dp[n+1][d+1][m+1][3];
	int dpval[n+1][d+1][m+1];
	for (int i = 0; i <=n ; ++i)
	{
		for (int j = 0; j <= d; ++j)
		{
			for (int k = 0; k <= m; ++k)
			{
				// if(j)
				// 	dp[i][j][k] = -1;
				// else
					dp[i][j][k] = 0;
			}
		}
	}
	memset(dpval,0,sizeof(dpval));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= d; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				dp[i][j][k][0] = 
			}
		}
	}
	return dp[n][d][m];
}


int main(){
	int k,n,m;
	cin>>k>>n>>m;
	while(k||n||m){
		vpii v;
		pii temp;
		while(n--) cin>>temp.first>>temp.second, v.push_back(temp);
		n = v.size();
		cout<<ans(v,n,k,m)<<endl;
		cin>>k>>n>>m;
	}
}