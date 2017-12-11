#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ans(const string &s ){
	ll dp[3];
	dp[0] = 1;
	int f = 1;
	for (int i = 1; i <= s.length(); ++i,f++,f%=3)
	{
		dp[f] = 0;
		int x,y;
		string sub2 = s.substr(i-1,1);
		y = atoi(sub2.c_str());
		if(y) dp[f]+=dp[(f+2)%3];
		if(i>1){
			string sub = s.substr(i-2,2);
			x = atoi(sub.c_str());
			if(x<=26&&x>=10) dp[f]+=dp[(f+1)%3];
		}
	}
	return dp[(f+2)%3];
}

int main(){
	while(1){
		string s;
		cin>>s;
		if(s==string("0"))
			break;
		cout<<ans(s)<<endl;
	}
	return 0;
}