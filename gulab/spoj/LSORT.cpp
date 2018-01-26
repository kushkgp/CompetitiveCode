#include <bits/stdc++.h>
#define pb push_back 
#define ff first
#define ss second
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef pair< int,int > pii;
typedef vector< pii > vpii;

int ans(const vpii & v, int n){
	int X[n][n];
	int Y[n][n];
	int dp[n][n];
	for (int i = 0; i < n; ++i)
	{
		X[i][i] = v[i].ss+1;
		for (int j = i+1; j < n; ++j)
			X[i][j] = X[i][j-1] - (v[j].ss < v[i].ss?1:0);
	}
	for (int i = n-1; i>=0; --i)
	{
		Y[i][i] = v[i].ss+1;
		for (int j = i+1; j < n; ++j){
			Y[i][j] = Y[i+1][j] - (v[i].ss < v[j].ss?1:0);
			// if(i==1&&j==2)
			// 	cout<<Y[i+1][j]<<endl;
		}
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			int j = i+k;
			if(k)
				dp[i][j] = min(dp[i+1][j]+(k+1)*(X[i][j]),dp[i][j-1]+(k+1)*Y[i][j]);
			else
				dp[i][i] = v[i].ss+1;
		}
	}
	return dp[0][n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vpii v;
		pii temp;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp.ff;
			temp.ss = i;
			// cout<<temp.ff<<" "<<temp.ss<<endl;
			v.pb(temp);
		}
		sort(v.begin(),v.end());
		// tr(v,i) cout<<i->ff<<" "<<i->ss<<endl;
		cout<<ans(v,n)<<endl;
	}
}