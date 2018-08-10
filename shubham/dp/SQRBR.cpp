#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int solve(int n,map<int,int> &m)
{
	int t= n<<1;
	int dp[t + 1][t];
	for(int i=t ; i>0;i--)
		for(int j=0;j<i;j++)
		{
			if(i == t)
			{
				if(m.find(t) != m.end())
				{
					dp[i][j] = 0;
					continue;
				}
				if(j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = dp[i+1][j+1];
				if(j>0 && m.find(i) == m.end())
					dp[i][j] += dp[i+1][j-1];



			}
		}

	return dp[1][0];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		map<int,int> m;
		for(int i=0;i<k;i++)
		{
			int x;
			scanf("%d",&x);
			m[x]=1;
		}
		printf("%d\n",solve(n,m));

	}
}