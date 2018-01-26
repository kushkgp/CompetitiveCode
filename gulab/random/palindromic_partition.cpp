#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int maxpalindrone(string a,int n){
	int p[n+1][n+1],dp[n+1][n+1];
	for (int i = 0; i < n; ++i)
	{
		p[i][i]=1;
		p[i][i+1]=1;
		dp[i][i]=0;
		dp[i][i+1]=0;

	}
	p[n][n]=1;
	dp[n][n]=0;
	for (int i = n; i >= 0; --i)
	{
		for (int j = i+2; j < n+1; ++j)
		{
			if(p[i+1][j-1]&&a[i]==a[j-1])
				p[i][j]=1;
			else p[i][j]=0;

			if(p[i][j])
				dp[i][j]=0;
			else{
				int min=INT_MAX;
				for (int k = i+1; k < j; ++k)
				{
					int x=1+dp[i][k]+dp[k][j];
					if(min>x)
						min=x;
				}
				dp[i][j]=min;
			}
		}
	}
	return dp[0][n];
}

int main(){
	string s;
	cin>>s;
	cout<<maxpalindrone(s,s.length())<<endl;
	return 0;
}
