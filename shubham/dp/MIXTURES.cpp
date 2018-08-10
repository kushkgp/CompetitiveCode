#include<bits/stdc++.h>
using namespace std;

struct data{
	int color;
	int smoke;

};

#define vi vector<int>

int solve(vi &v,int n)
{
	data dp[n][n];
	for(int i=n-1;i>=0;i--)
	{
		for(int j=i;j<n;j++)
		{
			if(i == j)
			{
				dp[i][j].color = v[i];
				dp[i][j].smoke = 0;
				continue;
			}
			dp[i][j].smoke = INT_MAX;
			for(int k=i;k<j;k++)
			{
				int smoke = dp[i][k].color * dp[k+1][j].color + dp[i][k].smoke + dp[k+1][j].smoke;
				if(smoke < dp[i][j].smoke)
				{
					dp[i][j].smoke = smoke;
					dp[i][j].color = (dp[i][k].color + dp[k+1][j].color)%100;
				}
			}
		}
	}
	return dp[0][n-1].smoke ;
}

int main()
{
	string s;
	getline(cin,s);
	while(!s.empty())
	{

		stringstream ss(s);
		int n;
		ss>>n;
		vi v(n);
		getline(cin,s);
		stringstream ss1(s);
		for(int i=0;i<n;i++)
			ss1>>v[i];
		printf("%d\n", solve(v,n));
		getline(cin,s);
	}
}