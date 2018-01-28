/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
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
	int t,C=1;
	cin >> t;
	// cout << endl;
	while(t--){
		int n;
		cin >> n;
		ll l = 0;
		ll r = 1e15;
		F1(i,0,n-1){
			ll p,f;
			cin >> p >> f;
			if(p==100){
				r = min(r,f);
				l = max(l,f);
				continue;
			}
			if(p>0){
				r = min(r,(100*f)/p);
				// l = max(l,(100*f)%(p+1)?(100*f+p)/(p+1):(100*f+p)/(p+1)-1);
			}
			l = max(l,(100*f)/(p+1)+1);
			// cout << l << " " << r << endl;
		}
		ll ans = -1;
		if(l==r){
			ans = r;
		}
		cout << "Case #" << C++ <<": " << ans << endl;
	}
}