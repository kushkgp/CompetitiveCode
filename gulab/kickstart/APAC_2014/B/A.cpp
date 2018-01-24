/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t;
	cin>>t;
	int cnt = 1;
	while(t--){
		int n,m;
		cin>>m>>n;
		vvi dp(n+1,vi(m+1,0));
		dp[1][1]=1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				if(i!=1||j!=1)
					dp[i][j] = ((ll)j*((dp[i-1][j-1]+dp[i-1][j])%MOD))%MOD;
		}
		printf("Case #%d: %d\n",cnt++,dp[n][m]);
	}
}