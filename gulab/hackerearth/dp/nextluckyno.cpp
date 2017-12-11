#include <bits/stdc++.h>
using namespace std;

typedef struct family
{
	int no;
	int prev;
}digit;

void ans(string s,int n){
	digit dp[2][n+1];
	dp[0][0].no=0;
	dp[1][0].no=3;
	for (int i = 1; i <= n; ++i)
	{
		dp[0][i].no = -1;
		dp[0][i].prev = 0;
		if(dp[0][i-1].no!=-1){
			if(s[i-1]=='3')
				dp[0][i].no=3;
			else if(s[i-1]=='5')
				dp[0][i].no=5;
		}
		dp[1][i].no = 3;
		dp[1][i].prev = 1;
		if(dp[0][i-1].no!=-1){
			if(s[i-1]-'0'<5){
				// printf("hi\n");
				dp[1][i].no=5;
				dp[1][i].prev = 0;
				if(s[i-1]-'0'<3)
					dp[1][i].no=3;
			}
		}
	}
	// cout<<"HI"<<endl;
	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout<<dp[1][i].prev<<" ";
	// }
	// cout<<endl;
	char temp[n+2];
	temp[n+1]='\0';
	temp[n] = dp[1][n].no +'0';
	int prev = dp[1][n].prev;
	for (int i = n-1; i>=0; --i)
	{
		// printf("prev = %d\n",prev );
		temp[i] = dp[prev][i].no + '0';
		prev = dp[prev][i].prev;
	}
	if(temp[0]=='0')
		printf("%s\n", &temp[1]);
	else printf("%s\n", temp);
}


int main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		ans(s,s.length());
	}
}