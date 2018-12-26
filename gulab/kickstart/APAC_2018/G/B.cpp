/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007
#define prll(test_case, ans) cout << "Case #" << test_case << ": " << ans << "\n"

using namespace std;
typedef long long int ll;
template <typename x> using v = vector<x>;
template <typename x> using vv = v<v<x> >;

int main(){
	ll t, cnt = 1;
	cin>>t;
	while(t--){
		ll n, qs;
		cin>>n>>qs;
		auto next = [](ll x, ll y, ll a, ll b, ll c, ll m)->ll{
			return ((ll)y*a+(ll)x*b+c)%m;
		};
		ll tot = 0;
		ll x, y, a, b, c, m;
		v<ll> l(n, INT_MAX), r(n, INT_MIN);
		v<ll> q(qs);
		auto fill = [&](){
			cin>>x>>y>>a>>b>>c>>m;
			l[0] = min(x+1, l[0]); 
			l[1] = min(y+1, l[1]);
			r[0] = max(x+1+1, r[0]);
			r[1] = max(y+1+1, r[1]);
			F1(i, 2, n-1){
				ll nx = next(x, y, a, b, c, m);
				l[i] = min(l[i], nx+1);
				r[i] = max(r[i], nx+2);
				x = y;
				y = nx;
			}
		};
		fill();
		fill();
		cin>>x>>y>>a>>b>>c>>m;
		q[0] = x+1; 
		if(qs>1)
			q[1] = y+1;
		F1(i, 2, qs-1){
			ll nx = next(x, y, a, b, c, m);
			q[i] = nx+1;
			x = y;
			y = nx;
		}
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		v<ll> prel(n), prer(n);
		F1(i, 0, n-1){
			prel[i] = l[i] + (i?prel[i-1]:0);
			prer[i] = r[i] + (i?prer[i-1]:0);
		}
		F1(i, 0, n-1){
			tot += r[i] - l[i];
		}

		auto bs = [&](ll q)->ll{
			auto find = [&](v<ll> & a, v<ll> & pa, ll k)->ll{
				auto it = upper_bound(all(a), k);
				if(it == a.begin())
					return 0;
				ll x = it - a.begin() -1;
				return (x+1)*k - (pa[x]) + x+1;
			};
			if(q > tot)
				return 0ll;
			ll x = 0;
			ll li = 1, ri = 1e9;
			while(li <= ri){
				ll m = (li+ri)>>1;
				if(find(l, prel, m) - find(r, prer, m) >= tot - q + 1){
					x = m;
					ri = m-1;
				}
				else
					li = m+1;
			}
			return x;
		};
		cout << "Case #" << cnt++ << ": ";
		ll sum = 0;
		F1(i, 0, qs-1){
			sum += (i+1)*bs(q[i]);
		}
		cout<<sum<<endl;
	}
}