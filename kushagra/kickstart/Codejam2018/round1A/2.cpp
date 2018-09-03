/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define min3(a,b,c) (min(min(a,b),c))
#define max3(a,b,c) (max(max(a,b),c))
#define mod 1000000007
#define inf INT_MAX

#define F2(x,y,z) for(int x = y; x >= z; x--)
#define F1(x,y,z) for(int x = y; x <= z; x++)
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define ss second
#define ff first
#define mp make_pair
#define pb push_back

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;

int main(){
	int C = 1;
	int t; cin >> t;
	while (t--) {
		int r,b,c;
		cin >> r >> b >> c;
		vi m(c),s(c),p(c), taken(c,0);
		vector<pair<double,int> > g(c);
		ll R = 0;
		F1(i,0,c-1){
			cin >> m[i] >> s[i] >> p[i];
			R = max(R,(ll)m[i]*s[i]+p[i]);
		}
		ll l = 0;
		// int mid;
		while(l<R){
			cout << l << " " << R << "-=-=-=--=" <<  endl;
			int mid = (l+R)/2;
			int ans = 0;
			F1(i,0,c-1){
				cout << mid << " " << p[i] << " " << s[i] << endl;
				if(p[i]<mid){
					cout << mid << " " << p[i] << " " << s[i] << " " << ans << endl;
					ans += min((mid-p[i])/s[i],m[i]);
				}
			}
			// cout << ans << endl;
			if(ans < b)
				l = mid+1;
			else
				R = mid;
		}

		cout << "Case #" << C++ << ": "<< R << endl;
	}	

	return 0;
}