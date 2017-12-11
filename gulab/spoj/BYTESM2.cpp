#include <bits/stdc++.h>
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;

int ans(const vvi v, int h, int w){
	int dp[h][w];
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			dp[i][j] = 0;
			if(i){
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
				if(j)
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
				if(j<w-1)
					dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
			}
			dp[i][j] += v[i][j];
		}
	}
	int retmax = 0;
	for (int i = 0; i < w; ++i)
	{
		retmax=max(retmax,dp[h-1][i]);
	}
	return retmax;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int h,w;
		cin>>h>>w;
		vvi v;
		v.resize(h,vi(w,0));
		tr(v,it)
			tr(*it,it1)
				cin>>*it1;
		cout<<ans(v,h,w)<<endl;
	}
	return 0;
}