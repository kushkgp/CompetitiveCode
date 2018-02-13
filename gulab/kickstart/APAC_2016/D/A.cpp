/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vv<double> dp(n+1,v<double>(m+1,0));
		dp[1][0] = 1;
		F1(i,1,n){
			F1(j,0,m){
				if(i>j){
					if(j) dp[i][j] += (dp[i][j-1]*j)/(i+j);
					dp[i][j] += (dp[i-1][j]*i)/(i+j);
				}
			}
		}
		printf("Case #%d: %.8lf\n", cnt++, dp[n][m]);
	}
}