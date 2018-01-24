#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void longest_palidromic_substr(const string & a,int n){
	int p[n+1][n+1];
	int dp[n+1][n+1];
	for (int i = 0; i < n; ++i)
	{
		p[i][i]=p[i][i+1]=dp[i][i+1]=1;
		dp[i][i]=0;
	}
	int start = 0,len = 1;
	for (int k = 2; k <= n; ++k){
		for (int i = 0; i <= n-k; ++i)
		{
			int j = i+k;
			if (p[i+1][j-1] && a[i]==a[j-1]){
				p[i][j]=1;
				dp[i][j]=2+dp[i+1][j-1];
				start = i;
				len = k;
			}
			else{
				p[i][j]=0;
			}
		}
	}
	cout<<a.substr(start,len)<<endl;
}
int main(){
	string s;
	getline(cin,s);
	longest_palidromic_substr(s,s.length());
	return 0;
}
