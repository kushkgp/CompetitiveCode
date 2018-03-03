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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef v<pii> vpii;

#define N 10000
bool phi[10001];
vi primes;

void precompute(){
	fill(begin(phi),end(phi),false);
	F1(i,2,N)
		if(!phi[i]){
			primes.pb(i);
			for(int j = i; j*i<=N; j++)
				phi[i*j] = true;
		}
}

int main(){
	precompute();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans = 1;
		F1(i,0,primes.size()-1 && primes[i]<=n){
			int p = primes[i];
			while(p<=n)
				p*=primes[i];
			p/=primes[i];
			ans*=p;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
}
