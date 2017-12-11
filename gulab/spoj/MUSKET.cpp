#include <bits/stdc++.h>
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef vector<bool> vi;
typedef vector<vi> vvi;

int ans(const vvi & v, int n){
	int dp[n][n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vvi v;
		v.resize(n,vi(n,0));
		char c,s[100];
		fgets(s,100,stdin);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin>>c;
				if(c=='1')
					v[i][j]=1;
			}
			fgets(s,100,stdin);
		}
		cout<<endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<v[i][j];
			}
			cout<<endl;
		}
		ans(v,n);
	}
}