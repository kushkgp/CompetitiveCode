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
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){
	BOOST;

	int t, cnt = 1;
	
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		vi b, c, a(n);
		F1(i, 0, n-1){
			int x;
			cin>>x;
			if(i&1)
				c.pb(x);
			else
				b.pb(x);
		}
		sort(all(b));
		sort(all(c));
		F1(i, 0, n-1){
			if(i&1)
				a[i] = c[i>>1];
			else
				a[i] = b[i>>1];
		}
		int ans = -1;
		F1(i, 0, n-2){
			if(a[i]>a[i+1]){
				ans = i;
				break;
			}
		}
		printf("Case #%d: %s\n", cnt++, ans==-1?"OK":to_string(ans).c_str());
	}
}