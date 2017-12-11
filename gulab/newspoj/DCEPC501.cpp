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

ll ans(const vi& v, int n){
	ll dp[n];
	for (int i = n-1; i>=0; --i)
	{
		dp[i] = v[i]+(i+2<n?dp[i+2]:0);
		if(i+1<n){
			dp[i] = max(dp[i],v[i]+v[i+1]+(i+4<n?dp[i+4]:0));
			if(i+2<n)
				dp[i] = max(dp[i],v[i]+v[i+1]+v[i+2]+(i+6<n?dp[i+6]:0));
		}
	}
	return dp[0];
}

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		cout<<ans(v,n)<<endl;
	}
}