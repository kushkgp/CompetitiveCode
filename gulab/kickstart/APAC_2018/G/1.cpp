#include <bits/stdc++.h>
using namespace std;

#define IOS std::ios_base::sync_with_stdio(false); cin.tie(NULL)

#define mp make_pair
#define F first
#define S second

#define out(x) cout<<x<<"\n"
#define out2(x,y) cout<<x<<" "<<y<<"\n"
#define out3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define test(t,x) cout<<t<<" "<<x<<"\n"
#define test2(t,x,y) cout<<t<<": "<<x<<" "<<y<<"\n"

#define ress(cs, ans) cout << "Case #" << cs << ": " << ans << "\n"

typedef long long int ll;
const long long int mod = 1000000007;

const int N = 100055;
const int MAX = 10000005;

int main() {
	IOS;
	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		ll num = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 0)
				num ++;
		}
		sort(a.rbegin(), a.rend());
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			unordered_map<ll, ll> store;
			store.clear();
			for(int j = 0; j < i; j++) {
				ll prod = a[i] * a[j];
				if(prod > a[0])
					break;
				if(store.find(prod) != store.end())
					ans += store[prod];
				store[a[j]]++;
			}
		}
		ll temp = (num*num - num)/2LL;
		ans += temp * (n-num);
		ress(cs, ans);
	}
	return 0;
}