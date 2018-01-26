#include <bits/stdc++.h>
using namespace std;


bool optwin(int *a,int m,int n){
	bool dp[m+1];
	fill(dp,dp+m+1,false);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i>=a[j])
				dp[i]+=(!dp[i-a[j]]);
			else
				break;
		}
	}
	return dp[m];
}


int main(){
	int t,n,m,*a;
	cin>>t;
	while(t--){
		cin>>m>>n;
		a = new int[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		if(optwin(a,m,n))
			printf("Little Deepu\n");
		else printf("Kate\n");;
		delete a;
	}
	return 0;
}