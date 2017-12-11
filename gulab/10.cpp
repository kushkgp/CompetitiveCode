#include <bits/stdc++.h>
#define N 1024
#define rem 100000007
using namespace std;

int ans(int a[],int b[],int n,int m){
	int dp[n+1][N];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j^a[i-1]])%rem;
			// dp[i][j]=(dp[i][j]+dp[i-1][j])%rem;
			// dp[i][j^a[i-1]]=(dp[i][j^a[i-1]]+dp[i-1][j])%rem;
		}
		// cout<<dp[i][3]<<endl;
	}

	int sum=0;
	// cout<<binary_search(v.begin(),v.end(),3)<<"hi"<<endl;
	for (int i = 0; i < N; ++i){
	// 	if(i==1)
	// 		cout<<dp[1][0^a[1]]<<endl;
		if((!binary_search(b,b+m,i))&&dp[n][i]){
			sum=(sum+dp[n][i])%rem;
			// cout<<"hello"<<i;
		}
	}
	return sum;
}

int main(){
	int t,*a,*b,n,m;
	cin>>t;
	int x=1;
	while(t--){
		cin>>n>>m;
		a=new int[n];
		b=new int[m];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>b[i];
			// cout<<i<<" "<<b[i]<<endl;
		}
		sort(b,b+m);

		cout<<"Case "<<x<<": "<<ans(a,b,n,m)<<endl;
		delete a;
		delete b;
		x++;
	}
	return 0;
}