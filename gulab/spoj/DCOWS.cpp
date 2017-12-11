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
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

ll ans(const vi& b, const vi& c, int n, int m){
	ll dp[2][m+1];
	for (int i = 0; i <= m; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= m; ++j)
		{
			dp[i%2][j] = dp[(i+1)%2][j-1]+abs(b[i]-c[j]);
			if(j>i){
				dp[i%2][j] = min(dp[i%2][j],dp[i%2][j-1]);
			}
		}
	}
	return dp[n%2][m];
}

int main(){
	int n,m;
	BOOST;
	cin>>n>>m;
	// cout<<LONG_MAX<<endl;
	vi b,c;
	b.resize(n+1);
	c.resize(m+1);
	b[0] = c[0] =0;
	for (int i = 1; i <= n; ++i)
		cin>>b[i];
	for (int i = 1; i <= m; ++i)
		cin>>c[i];
	asort(b);
	asort(c);
	cout<<ans(b,c,n,m)<<endl;
}