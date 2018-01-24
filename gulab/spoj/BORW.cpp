/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
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
typedef vector< pii > vpii;

int ans(const vi &v, int r){
	int n = v.size();
	int dp[2][r+2][r+2];
	memset(dp,0,sizeof(dp));
	int f = 0;
	for (int i = 0; i < n; ++i,f^=1)
	{
		for (int j = 0; j <= r+1; ++j)
		{
			for (int k = 0; k <= r+1; ++k)
			{
				dp[f][j][k] = dp[f^1][j][k];
				if(v[i]<=j)
					dp[f][j][k] = max(dp[f][j][k],dp[f^1][v[i]-1][k]+1);
				if(v[i]>=k)
					dp[f][j][k] = max(dp[f][j][k],dp[f^1][j][v[i]+1]+1);
			}
		}
	}
	return dp[(n-1)%2][r][1];
}

int main(){
	BOOST;
	int n;
	cin>>n;
	while(n!=-1){
		vi v;
		vpii p;
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			p.pb(mp(v[i],i));
		}
		asort(p);
		int j = 1;
		FOR(i,n){
			v[p[i].ss] = j;
			if(i<n-1){
				if(p[i].ff!=p[i+1].ff)
					j++;
			}
		}
		cout<<n-ans(v,j)<<endl;
		cin>>n;
	}
	return 0;
}