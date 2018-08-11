#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int cnt[26];
map<char,int> m;
void setval(char a,int n)
{
	int t =(int) a - 'A';
	cnt[t] = n % mod;
}


int get_dsubseq(string &s , int n)
{
	int dp[n];
	dp[0] = 1;
	setval(s[0],1);
	for(int i=1;i<n;i++)
	{
		int ans = 1 + 2*dp[i-1];
		ans %= mod;
		int t = (int) s[i] - 'A';
		ans = (ans - cnt[t] + mod)%mod;
		dp[i] = ans;
		setval(s[i],dp[i-1]+1);
	}
	return (dp[n-1]+1)%mod;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof cnt);
		string s;
		cin>>s;
		printf("%d\n", get_dsubseq(s,s.size()));
	}
}