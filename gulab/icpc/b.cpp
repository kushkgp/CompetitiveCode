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
typedef pair<int,ll> pill;
typedef vector<pii> vpii;
typedef vector<ll> vll;


int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n,m = INT_MAX;
		cin>>n;
		vpii v(n);
		FOR(i,n)
			cin>>v[i].ff;
		FOR(i,n){
			cin>>v[i].ss;
			v[i].ff = v[i].ff%v[i].ss;
			m = min(m,v[i].ss);
		}
		asort(v);
		vll c(n),b(n);
		FOR(i,n){
			if(i){
				c[i] = c[i-1]+v[i].ff;
				b[i] = b[i-1]+v[i].ss;
			}
			else{
				c[i] = v[i].ff;
				b[i] = v[i].ss;
			}
		}
		ll ans = b[n-1]-c[n-1];
		for(int i = 0;i<n && v[i].ff<m;i++ ){
			ll x = i?(ll)i*v[i].ff-c[i-1]:0;
			x+=b[n-1]-b[i];
			x-=c[n-1]-c[i];
			x+=(ll)(n-i-1)*v[i].ff;
			ans = min(ans,x);
		}
		cout<<ans<<endl;
	}
	return 0;
}