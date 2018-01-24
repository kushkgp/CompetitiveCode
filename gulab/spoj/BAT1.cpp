/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int ans(const vvi & v, const vvi & p, const vi & c, int n, int m, int K){
	int dp[n+1][m+1][K+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k <= K; ++k)
			{
				if(!i){
					dp[i][j][k] = 0;
					continue;
				}
				if(j==m){
					dp[i][j][k] = dp[i-1][j][k];
					if(k>=c[i])
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-c[i]]);
				}
				else{
					if(!j)
						dp[i][j][k] = dp[i-1][m][k];
					else
						dp[i][j][k] = dp[i][j-1][k];
					if(k>=p[i][j])
						dp[i][j][k] = max(dp[i][j][k],v[i][j]+dp[i][j][k-p[i][j]]);
				}
			}
		}
	}
	return dp[n][m][K];
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vi c(n+1);
		vvi p(n+1, vi(m));
		vvi v(n+1, vi(m));
		for (int i = 1; i <= n; ++i)
			cin>>c[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>p[i][j];
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>v[i][j];
		cout<<ans(v,p,c,n,m,k)<<endl;
	}
}