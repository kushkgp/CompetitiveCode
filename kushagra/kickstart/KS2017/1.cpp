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

ll get_inverse(ll a){
	ll ans=1;
	ll crt = a;
	ll exo = mod-2;
	while(exo){
		if(exo&1){
			ans*=crt;
			ans%=mod;
		}
		exo>>=1;
		crt*=crt;
		crt%=mod;
	}
	return ans;
}

ll compute(ll a, ll b){
	if(a<b)
		swap(a,b);
	ll ans = (((a*b)%mod)*3)%mod;
	// cout<< "1 " << ans << endl;
	ans -= ((a+b)*(2*b - 1)%mod);
	// cout << "2 " << ans << endl;
	ans += mod;
	ans %= mod;
	ans += (((b*(b-1)/2)%mod)*3)%mod;
	ans %= mod;
	// cout << "3 " << ans << endl;
	ans *= (b*(b-1)/2)%mod;
	ans %= mod;
	// cout << "4 "<< ans << endl;
	ans *= get_inverse(3);
	ans %= mod;
	return ans;
}

int main(){
	int t,C=1;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << "Case #"<<C++<<": "<< compute(a,b) << endl;
	}
}