#include <bits/stdc++.h>
using namespace std;


int ans(int **a,int N,int M, int K){
	int dp[N][M][K+1];
	int temp = 0;
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		temp+= a[0][i];
		for (int j = 0; j < K+1; ++j)
		{
			if(j==temp){
				dp[0][i][j]=1;
				// printf("\n%d %d\n",i,j );
			}
		}
	}
	for (int i = 1; i < N; ++i)
	{
		for(int j=0;j<M;j++){
			for (int k = 0; k < K+1; ++k)
			{
				dp[i][j][k]=0;
				// if(k)
				// 	dp[i][j][k]|=dp[i][j][k-1];
				if(k>=a[i][j]){
					dp[i][j][k]|=dp[i-1][j][k-a[i][j]];
					if(j){
						dp[i][j][k]|=dp[i][j-1][k-a[i][j]];
						dp[i][j][k]|=dp[i-1][j-1][k-a[i][j]];
					}
				}

			}
		}
	}
	int ret=-1;
	for (int i = K; i >=0; --i)
	{
		// printmatrix(dp,N,M,i);
		if(dp[N-1][M-1][i])
			return i;
	}
	return -1;
}


int main(){
	int N,M,K;
	int t;
	cin>>t;
	while(t--){
		cin>>N>>M>>K;
		int **a= new int*[N];
		for (int i = 0; i < N; ++i)
		{
			a[i]=new int[M];
			for (int j = 0; j < M; ++j)
			{
				cin>>a[i][j];
			}
		}

		cout<<ans(a,N,M,K)<<endl;


		for (int i = 0; i < N; ++i)
		{
			delete a[i];
		}
		delete a;
	}
}