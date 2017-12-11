#include <bits/stdc++.h>
using namespace std;

int ans(int l,int d){
	int dp1[l+1][d+1],dp2[l+1][d+1];
	for (int i = 0; i <= l; ++i)
	{
		for (int j = 0; j <= d; ++j)
		{
			if(j==0||i==0){
				dp2[i][j]=0;
				if(i==0&&j==0){
					dp1[i][j]=1;
				}
				else
					dp1[i][j]=0;
				continue;
			}

			dp1[i][j]=dp1[i-1][j-1]+dp2[i-1][j-1];
			dp2[i][j]=0;
			for (int m = 1; m < i; ++m)
			{
				for (int n = 1; n < j; ++n)
				{
					dp2[i][j]+=dp2[i-m][j]*dp1[m][n];
					dp2[i][j]+=dp1[i-m][j]*dp2[m][n];
				}
				dp2[i][j]+=dp1[i-m][j]*dp2[m][j];
			}
			dp2[1][1]=1;
			cout<<i<<" "<<j<<" "<<dp1[i][j]<<" "<<dp2[i][j]<<endl;
		}
	}
	return dp2[l][d]+dp1[l][d];
}

int main(){
	int n=10,l,d;
		cin>>l>>d;
		cout<<ans(l,d)<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// }
	return 0;
}