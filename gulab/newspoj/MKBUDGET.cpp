#include <bits/stdc++.h>
#define size1 1000
using namespace std;
typedef vector<int> vi; 

int ans(const vi & month, int maxelement, int n, int hire, int salary, int severence){
	int dp[n][maxelement+1];
	for (int i = 0; i <= maxelement; ++i)
	{
		dp[0][i] = -1;
		if(month[0]<=i) dp[0][i] = i*(hire+salary);
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= maxelement; ++j)
		{
			if(month[i]>j)
				dp[i][j] = -1;
			else{
				dp[i][j] = INT_MAX;
				for (int k = 0; k <= maxelement; ++k)
				{
					if(dp[i-1][k]==-1)
						continue;
					else{
						int x=salary*j;
						if(j>=k) x += hire*(j-k);
						else x += severence*(k-j);
						dp[i][j] = min(dp[i-1][k]+x,dp[i][j]);
					}
						// if(i==1&&j==9)
						// 	cout<<dp[i][j]<<endl;
				}
			}
		}
	}
	int retans = INT_MAX;
	for (int i = month[n-1]; i <= maxelement; ++i)
	{
		retans = min(retans,dp[n-1][i]);
	}
	return retans;
}

int main(){
	int n;
	cin>>n;
	int i=1;
	while(n){
		int hire,salary,severence;
		cin>>hire>>salary>>severence;
		vi month;
		int temp;
		int maxelement = 0;
		while(n--) cin>>temp,month.push_back(temp),maxelement=max(maxelement,temp);
		n = month.size();
		cout<<"Case "<<(i++)<<", cost = $"<<ans(month,maxelement,n,hire,salary,severence)<<endl;
		cin>>n;
	}
}