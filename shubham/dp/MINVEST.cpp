#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> >

int solve(int A,int B,vi &bond_price,vi &bond_val,int bonds)
{
	int sum = A;
	int r = sum % 1000;
	sum /= 1000;
	int years = B;
	int initA = 0;
	int **dp = new int*[sum+1];
	for(int i=0;i<=sum;i++)
	{
		dp[i] = new int[bonds+1];
		if(i==0)
		{
			for(int j=0;j<=bonds;j++)
				dp[i][j] = 0;
		}
	}
	while(years--)
	{
		for(int i = initA+1;i<=sum;i++)
			for(int j=0;j<=bonds;j++)
			{
				if(j==0)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = dp[i][j-1];
				if(bond_price[j-1]/1000 <= i)
					dp[i][j] = max(dp[i][j] , dp[i-(bond_price[j-1]/1000)][j] + bond_val[j-1]);
			}


		initA = sum;
		sum *= 1000;
		sum += dp[sum/1000][bonds];
		sum += r;
		r = sum % 1000;
		sum /= 1000; 
		int **temp = new int*[sum+1];
		for(int i=0;i<=initA;i++)
			temp[i] = dp[i];
		for(int i = initA + 1;i<=sum;i++)
			temp[i] = new int[bonds+1];
		delete[] dp;
		dp = temp;
	}
	// cout<<r<<endl;
	return (sum*1000) + r;

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int sum,years;
		scanf("%d%d",&sum,&years);
		int bonds;
		scanf("%d",&bonds);
		vi bond_price(bonds),bond_val(bonds);
		for(int i=0;i<bonds;i++)
		{
			cin>>bond_price[i]>>bond_val[i];
		}
		printf("%d\n", solve(sum,years,bond_price,bond_val,bonds));
	}
}