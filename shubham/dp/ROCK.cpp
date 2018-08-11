#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int solve(string &s,int n)
{
	// cout<<s;
	int dp[n+1];
	dp[0] = 0;
	for(int i=1;i<=n;i++)
	{
		dp[i] = dp[i-1];
		int sweet = 0;
		int sour = 0;
		for(int j=i;j>0;j--)
		{
			if(s[j-1] == '1')
				sweet++;
			else
				sour++;
			if(sweet > sour)
			{
				dp[i] = max(dp[i],dp[j-1]+ i-j+1);
			}
			// if(i==3)
			// {
			// 	cout<<j-1<<" "<<s[j-1]<<" "<<sweet<<" "<<sour<<endl;
			// }

		}
	}
	// for(int i=0;i<=n;i++)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	return dp[n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;
		printf("%d\n", solve(s,n));
	}
}