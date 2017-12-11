#include <bits/stdc++.h>
#define rem 1000000009
using namespace std;

void ans(string b,string e,int n){
	long long int dp1[n][n],dp0[n][n];
	memset(dp1,0,sizeof(dp1));
	memset(dp0,0,sizeof(dp0));
	for (int i = 0; i < n; ++i)
	{
		if(b[i]=='1')
			dp1[i][i]=1;
		else
			dp0[i][i]=1;
	}

	for (int k = 1; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			for (int j = i; j < i+k; ++j)
			{
				switch(e[j]){
					case 'a':dp1[i][i+k]+=(dp1[i][j]*dp1[j+1][i+k])%rem;

							dp0[i][i+k]+= (dp1[i][j]*dp0[j+1][i+k])%rem;
							dp0[i][i+k]%=rem;
							dp0[i][i+k]+= (dp0[i][j]*dp1[j+1][i+k])%rem;
							dp0[i][i+k]%=rem;
							dp0[i][i+k]+= (dp0[i][j]*dp0[j+1][i+k])%rem;
							// if(i==0 && k==2)
							// 	printf("%d\n",dp0[i][i+k]);
							break;
					case 'o':dp0[i][i+k]+=(dp0[i][j]*dp0[j+1][i+k])%rem;

							dp1[i][i+k]+= (dp1[i][j]*dp0[j+1][i+k])%rem;
							dp1[i][i+k]%=rem;
							dp1[i][i+k]+= (dp0[i][j]*dp1[j+1][i+k])%rem;
							dp1[i][i+k]%=rem;
							dp1[i][i+k]+= (dp1[i][j]*dp1[j+1][i+k])%rem;
							break;
					case 'x':dp1[i][i+k]+=(dp1[i][j]*dp0[j+1][i+k])%rem;
							dp1[i][i+k]%=rem;
							dp1[i][i+k]+= (dp0[i][j]*dp1[j+1][i+k])%rem;

							dp0[i][i+k]+= (dp1[i][j]*dp1[j+1][i+k])%rem;
							dp0[i][i+k]%=rem;
							dp0[i][i+k]+= (dp0[i][j]*dp0[j+1][i+k])%rem;
							break;
				}
				dp1[i][i+k]%=rem;
				dp0[i][i+k]%=rem;  
			}
		}
	}
	// printf("%d\n",dp0[0][2]);
	int q,l,r;
	string s;
	cin>>q;
	while(q--){
		cin>>l>>r;
		cin>>s;
		// printf("%d\n",l);
		if(s=="true")
			cout<<dp1[l-1][r-1]<<endl;
		else
			cout<<dp0[l-1][r-1]<<endl;
	}
}

int main(){
	string b,e;
	cin>>b;
	cin>>e;
	ans(b,e,b.length());
}