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


int ans(const vpii& v, int l, int e){
	int dp[l][e+1];
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j <= e; ++j)
		{
			dp[i][j] = 0;
			if(i)
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			if(j>=v[i].ff)
				dp[i][j] = max(dp[i][j],v[i].ss+dp[i][j-v[i].ff]);
		}
	}
	return dp[l-1][e];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int e,l;
		cin>>e>>l;
		vpii v;
		v.resize(l);
		for (int i = 0; i < l; ++i)
		{
			cin>>v[i].ff;
		}
		for (int i = 0; i < l; ++i)
		{
			cin>>v[i].ss;
		}
		cout<<ans(v,l,e)<<endl;
	}
}