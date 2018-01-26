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
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int sieve[40000001];

void preprocess(vi & primes){
	for(ll i = 1; i <= 4e7; i++)
		sieve[i] = 1;

	for(ll i = 2; i*i <= 1e15; i++)
		if(sieve[i]){
			primes.pb(i);
			for(ll j = i*i; j <= 4e7; j+=i)
				sieve[j] = 0;
		}
}

int dp(ll n, vector<pair<ll,int> > & primeinno, map<ll,int> & m){
	if(m.find(n)!=m.end())
		return m[n];
	int sum = 0;
	ll t = n;
	while(n){
		sum += (n%10);
		n/=10;
	}
	n = t;
	if(sieve[sum])
		return m[n]=0;

	int f = 0;
	F1(i,0,(int)primeinno.size()-1){
		if(primeinno[i].ss){
			ll temp = n;
			ll a = primeinno[i].ff;
			while(temp%a == 0) temp/=a;
			primeinno[i].ss = 0;
			if(!dp(temp,primeinno,m))
				f = 1;
			primeinno[i].ss = 1;
			if(f) break;
		}
	}
	return m[n]=f;
}

int main(){
	int t, cnt = 1;
	vi primes;
	preprocess(primes);
	cin>>t;
	map<ll,	int> m;
	while(t--){
		ll n;
		cin>>n;
		ll temp = n;
		int ans = 0;
		vector<pair<ll,int> > primeinno;
		F1(i,0,(int)primes.size() - 1){
			int c = 0;
			while(temp%primes[i]==0) temp/=primes[i], c++;
			if(c)
				primeinno.pb(mp(primes[i],1));
		}
		if(temp>1)
			primeinno.pb(mp(temp,1));
		printf("Case #%d: %s\n", cnt++, (dp(n,primeinno,m))?"Laurence":"Seymour");
	}
}