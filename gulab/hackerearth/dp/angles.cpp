#include <bits/stdc++.h>
using namespace std;

int gcdf(int a,int b){
	return b==0? a : gcdf(b,a%b);
}

int main(){
	int n,k,a,dp[360];
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	int f = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(f)
			continue;
		if(a>=360)
			a-=360;
		if(a){
			int gcd = gcdf(360,a);
			if(gcd==1)
				f=1;
			// cout<<gcd<<endl;
			int temp = a;
			for (int j = 0; j < 360/gcd; ++j)
			{
				dp[temp] = 1;
				temp+=a;
				temp%=360;
			}
		}
		else{
			dp[0]=1;
		}
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>a;
		if(dp[a])
			cout<<"YES\n";
		else	
			cout<<"NO\n";
	}
}