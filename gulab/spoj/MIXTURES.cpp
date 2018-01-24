#include <bits/stdc++.h>
#define pb push_back
#define MOD 100 
using namespace std;
typedef vector<int> vi;


int ans(const vi & v, int n){
	int dp[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = INT_MAX;
		}
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			if(!k){
				dp[i][i] = 0;
				continue;
			}
			int j = i+k;
			for (int x = i; x < j; ++x)
			{
				int a = v[x];
				if(i)
					a-=v[i-1];
				a%=MOD;
				int b = v[j]-v[x];
				b%=MOD;
				dp[i][j] = min(dp[i][j],dp[i][x]+dp[x+1][j]+a*b);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	char s[100];
	fgets(s,MOD,stdin);
	if(s[strlen(s)-1]=='\n')
		s[strlen(s)-1] = '\0';
	while(strcmp(s,"")){
		// cout<<"hello"<<endl;
		int n;
		sscanf(s,"%d",&n);
		vi v;
		int temp;
		while(n--) cin>>temp, v.pb(temp);
		n = v.size();
		for (int i = 1; i < n; ++i)
		{
			v[i]+=v[i-1];
		}
		cout<<ans(v,n)<<endl;
		fgets(s,MOD,stdin);
		fgets(s,MOD,stdin);
		if(s[strlen(s)-1]=='\n')
			s[strlen(s)-1] = '\0';
		// cout<<"laskd"<<s<<"hi"<<endl;
	}
	return 0;
}