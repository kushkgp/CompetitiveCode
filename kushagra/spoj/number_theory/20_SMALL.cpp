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
typedef vector<pii> vii;
typedef vector<vii> vvii;

bool phi[(int)1e4+1];
ll n = (int)1e4;
ll k;
vi primes;

int precompute(){
	fill(begin(phi),end(phi),false);
	phi[0]=phi[1]=1;
	F1(i,2,n){
		if(!phi[i]){
			primes.pb(i);
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i]=true;
			}
		}
	}
	return 1;
}

int compute(int n, int p, ll &ans){
	ll expo=0;
	ll bs=p;
	while(n>=bs){
		expo++;
		bs*=p;
	}
	bs/=p;
	bs%=mod;
	ans*=bs;
	ans%=mod;
	return ans;
}

int main(){
	precompute();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll ans=1;
		F1(i,0,primes.size()-1){
			compute(n,primes[i],ans);
		}
		cout << ans << endl;
	}
}