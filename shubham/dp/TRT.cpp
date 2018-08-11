#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v , int n)
{
	int dp[n][n];
	for(int i=n-1;i>=0;i--)
		for(int j=n-1;j>=i;j--)
		{
			int k = i+n-j-1;
			if(i == k)
			{
				dp[i][j] = (j+1)*v[k];
				continue;
			}
			dp[i][j] = max((j+1)*v[i] + dp[i+1][j+1], (j+1)*v[k] + dp[i][j+1]); 
		}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	return dp[0][0];
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	printf("%d\n", solve(v,n));
}