#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int> >

int solve(int n,int m,int K,vvi &arr)
{
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
			if(arr[i-1][j-1] == 1)
				dp[i][j] += 1;
		}

	int ans[n][m];
	int answer = INT_MAX;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			map<int,int> M;
			M[0] = -1;
			for(int k=0;k<m;k++)
			{
				int t ;
				if(i == 0)
					t = dp[j+1][k+1];
				else
					t = dp[j+1][k+1] - dp[i][k+1];
				if(t >= K && M.find(t-K)!=M.end())
					answer = min(answer,(j-i+1)*(k-M[t-K]));
				M[t] = k;

			}
		}
	if(answer == INT_MAX)
		return -1;
	return answer;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		vvi arr(n,vector<int>(m));
		vector<string> input;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			input.push_back(s);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(input[i][j] == '.')
					arr[i][j] = 0;
				else
					arr[i][j] = 1;
				// cout<<arr[i][j]<<" ";
			}
			// cout<<endl;
		}
		printf("%d\n", solve(n,m,k,arr));
}
}