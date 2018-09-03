/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int n;
	cin >> n;
	vpii d(n,mp(0,0));

	F1(i,0,n-1){
		int l,w;
		cin >> l >> w;
		d[i] = mp(l,w);
	}
	asort(d);
	vpii dpd;
	int maxi = -1;
	F2(i,n-1,0){
		if(d[i].ss > maxi){
			dpd.pb(d[i]);
			maxi = d[i].ss;
		}
	}
	n = dpd.size();


	vl dp(n+1, 1e15);
	dp[0] = 0;

	F1(i,1,n){
		F1(j,0,i-1){
			dp[i] = min(dp[i], dp[j] + (ll)dpd[i-1].ss * dpd[j].ff);
		}
	}

	cout << dp[n] << endl;


}