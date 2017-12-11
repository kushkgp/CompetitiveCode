#include <bits/stdc++.h>
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef vector<int> vi; 

int ans(const vi &v, int n){
	int dp[n+1];
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i]=0;
		int sweet=0,sour=0;
		for (int k = i-1; k >=0 ; --k)
		{
			if(v[k])
				sweet++;
			else
				sour++;
			if(sweet>sour){
				dp[i] = max(dp[i],dp[k]+i-k);
			}
			else
				dp[i] = max(dp[i],dp[k]);
		}
	}
	return dp[n];
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char s[205];
		fgets(s,205,stdin);
		vi v;
		v.resize(n,0);
		char c;
		for (int i = 0; i < n; ++i)
		{
			cin>>c;
			if(c=='1')
				v[i] = 1;
		}
		cout<<ans(v,n)<<endl;
	}
}