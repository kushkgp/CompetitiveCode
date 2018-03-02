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

#define N 100000
bool phi[100001];
vi primes;

void precompute(){
	fill(begin(phi),end(phi),false);
	primes.pb(2);
	F1(i,3,N){
		if(i%2&&!phi[i]){
			primes.pb(i);
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = true;
		}
	}
}

void insert(map<int,int> & m, int a){
	F1(i,0,primes.size()-1){
		int cnt = 0;
		while(!(a%primes[i]))
			cnt++,a/=primes[i];
		if(cnt)
			m[primes[i]]+=cnt;

	}
	if(a!=1)
		m[a]++;
}

int main(){
	BOOST;
	precompute();
	int n;
	cin>>n;
	map<int,int> ma,mb,m;
	while(n--){
		int a;
		cin>>a;
		insert(ma,a);
	}
	cin>>n;
	while(n--){
		int b;
		cin>>b;
		insert(mb,b);
	}
	for(auto it : ma)
		if(mb.find(it.ff)!=mb.end())
			m[it.ff]=min(it.ss,mb[it.ff]);
	
	ll ans = 1;
	int f = 0;
	for(auto it : m){
		int cnt = it.ss;
		while(cnt--){
			ans*=it.ff;
			if(ans>=1e9) f=1;
			ans%=(int)1e9;
		}
	}
	if(f)
		cout<<setw(9)<<setfill('0');
	cout<<ans<<endl;
}