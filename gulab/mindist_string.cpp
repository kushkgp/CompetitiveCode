#include <iostream>
#include <string>
using namespace std;

int min(int x,int y,int z){
	return min(min(x,y),z);
}

int mindist(string s1,string s2,int l1,int l2){
	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
		for (int j = 0; j <= l2; ++j)
		{
			if (i==0)
				dp[i][j]=j;
			else if (j==0)
				dp[i][j]=i;
			else if (s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+ min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
			/* code */
		}
		return dp[l1][l2];
}
int main(){
 string str1, str2;

 cin>>str1>>str2;

 cout<<mindist(str1,str2,str1.length(),str2.length())<<endl;
 return 0;
}