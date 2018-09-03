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
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

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
	while(1){
		int n;
		cin >> n;
		if(n<0)
			return 0;
		vpii pr(n);

		F1(i,0,n-1){
			int l,r;
			cin >> l >> r;
			pr[i] = mp(l,r);
		}
		
		asort(pr);

		vi dp(n);

		int ans = 1;
		dp[n-1] = 1;
		F2(i,n-1,0){
			int ed = upper_bound(all(pr), mp(pr[i].ss,0)) - pr.begin();
			if(ed != n){
				ans += dp[ed];
				dp[i] = 2*dp[ed];
				dp[i] = dp[i]%1e9;
			}
		}


	}
}