#include <bits/stdc++.h>
using namespace std;

int count1(int n){
	int x=0;
	// cout<<"hello"<<endl;
	for (int i = 1; i <= n; i=i<<1)
	{
		if(n&i)
			x++;
	}
	return x;
}

unsigned long long int ans(int a[][20],int n){
	unsigned long long int dp[1<<n];
	dp[0]=1;
	for (int i = 1; i < 1<<n; ++i)
	{
		dp[i]=0;
		int k=count1(i);
		for (int j = 0; j < n; ++j)
		{
			int x = 1<<j;
			// cout << "x&i" << (x&i) << endl;
			if(a[k-1][j]&&((x&i))){
			x=~x;
			// cout << x << "gh\n"; 
			dp[i]+=dp[x&i];
			// cout<<i<<"asdf"<<((!x)&i)<<endl;
			}
		}
		// cout<<i<<" " <<dp[i]<<endl;
	}
	return dp[(1<<n)-1];
}

int main(){
	int t,n,a[20][20];
	cin>>t;
	// cout<<count1(t)<<endl;

	while(t){
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>a[i][j];
			}
		}
		cout<<ans(a,n)<<endl;
		t--;
	}

}