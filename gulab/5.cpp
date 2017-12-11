#include <bits/stdc++.h>
using namespace std;

int ans(int l,int l2,int d){
	int dp1[l+1][l2+1][d+1],dp2[l+1][l2+1][d+1];
	for (int i = 0; i <= l; ++i)
	{
		for (int k = 0; k <= l2; ++k)
		{
			for (int j = 0; j <= d; ++j)
			{
				if(j==0||i+k==0){
					dp2[i][k][j]=0;
					if(i==0&&j==0&&k==0){
						dp1[i][k][j]=1;
						dp2[i][k][j]=1;
					}
					else
						dp1[i][k][j]=0;
					continue;
				}
				if(i==0)
					dp1[i][k][j]=dp2[i][k-1][j-1];
				else
					dp1[i][k][j]=dp2[i-1][k][j-1];

				dp2[i][k][j]=dp1[i][k][j];
				for (int m = 1; m < i; ++m)
				{

					for (int n = 1; n < k; ++n)
					{
						for (int q = 1; q < j; ++q)
						{
							dp2[i][k][j]+=dp2[i-m][k-n][j]*dp1[m][n][q];
							dp2[i][k][j]+=dp1[i-m][k-n][j]*dp2[m][n][q];
						}
					dp2[i][k][j]+=dp1[i-m][k-n][j]*dp2[m][n][j];
					}
				}
				// cout<<i<<" "<<j<<" "<<dp1[i][j]<<" "<<dp2[i][j]<<endl;
			}
		}
	}
	return dp2[l][l2][d];
}

int main(){
	int n=10,l,d,l2;
		cin>>l>>l2>>d;
		cout<<ans(l2,l,d)<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// }
	return 0;
}