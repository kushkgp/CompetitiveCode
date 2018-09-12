/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define present(c,x) ((c).find(x) != (c).end())
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
using namespace std;
typedef long long int ll;

void ans(int (&dp)[2001][1001]){
	int n = 2000;
	memset(dp,0,sizeof(int)*(2001*1001));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n>>1; ++j)
		{
			if(i<j<<1)
				continue;
			dp[i][j] = (((ll)(i-(j<<1)))*dp[i-1][j])%MOD;
			if(j){
				dp[i][j]+= ((ll)j*dp[i-1][j-1])%MOD;
				dp[i][j]%= MOD;
				dp[i][j]+= (MOD - ((ll)j*dp[i-2][j-1])%MOD)%MOD;
				dp[i][j]%= MOD;
			}
		}
	}
}

int main(){
	BOOST;
	int a[2001][1001];
	ans(a);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int j=0;
		int temp;
		set<int> s;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			if(present(s,temp)){
				j++;
			}
			else
				s.insert(temp);
		}
		cout<<a[n][j]<<endl;
	}
}