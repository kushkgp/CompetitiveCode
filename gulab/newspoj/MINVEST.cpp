#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > pii;
typedef vector< pii > vpii;

int ans(int A, int n, const vpii & v, int d){
	int preA=0;
	int r = A%1000;
	A = A/1000;
	int **dp = new int*[A+1];
	for (int i = 0; i <= A; ++i)
	{
		dp[i] = new int[d+1];
	}
	for (int i = 0; i <= d; ++i)
	{
		dp[0][i] = 0;
	}
	while(n--){
		for (int i = preA+1; i <= A; ++i)
		{
			for (int j = 0; j <= d; ++j)
			{
				if(j){
					dp[i][j] = dp[i][j-1];
					if(i>=v[j-1].first/1000){
						dp[i][j]=max(dp[i][j],dp[i-v[j-1].first/1000][j]+v[j-1].second);
					}
				}
				else
					dp[i][j] = 0;
			}
		}
	// cout<<"hello"<<endl;
		preA = A;
		int profit = dp[A][d];
		A *=1000;
		A += r;
		A += profit;
		r = A%1000;
		A/=1000;
		int **temp = new int*[A+1];
		for (int i = 0; i <= preA; ++i)
			temp[i] = dp[i];
		delete[] dp;
		dp = temp;
		for (int i = preA+1; i <= A; ++i)
				dp[i] = new int[d+1];
	}
	delete[] dp;
	return A*1000 + r;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int A;
		cin>>A;
		int n;
		cin>>n;
		int d;
		cin>>d;
		vpii v;
		pii temp;
		while(d--) cin>>temp.first>>temp.second, v.push_back(temp);
		d = v.size();
		cout<<ans(A,n,v,d)<<endl;
	}
}