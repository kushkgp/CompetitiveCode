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
typedef vector<pii> vpii;

#define N 10000000
int phi[10000001];
vi primes;

void precompute(){
	memset(phi,0,sizeof(phi));
	primes.pb(2);
	F1(i,3,N){
		if((i+1)%2)
			phi[i]=1;
		if(!phi[i]){
			primes.pb(i);
			for(int j = i; (ll)j*i<N; j++)
				phi[i*j] = 1;
		}
	}
}

bool check(int f, vpii & va){
	F1(i,0,(int)va.size()-1){
		ll cnt = 0;
		ll x = va[i].ff;
		while(f>=x){
			cnt+=f/x;
			x*=va[i].ff;
		}
		if(cnt<va[i].ss)
			return false;
	}
	return true;
}

int bs(vpii & va){
	int l = 1, r = N;
	int x = N;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid,va)){
			x = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return x;
}

int main(){
	precompute();
	int a,b;
	cin>>a>>b;
	vpii va,vb;
	int x = a, y = b;
	F1(i,0,primes.size()-1){
		int cnt1 = 0, cnt2 = 0;
		while(!(x%primes[i]))
			cnt1++,x/=primes[i];
		while(!(y%primes[i]))
			cnt2++,y/=primes[i];
		if(cnt1)
			va.pb(mp(primes[i],cnt1));
		if(cnt2)
			vb.pb(mp(primes[i],cnt2));
	}
	cout<<max(0,bs(vb)-bs(va))<<endl;
}