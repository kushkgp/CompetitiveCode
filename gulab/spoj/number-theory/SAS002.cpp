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
typedef unsigned long long int ull;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef v<pii> vpii;

#define N 10000000
int phi[N/64+1];
vi primes;
#define gP(n) (phi[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (phi[n>>6]&=~(1<<((n>>1)&31)))

void precompute()
{
	memset(phi,-1,sizeof(phi));
	primes.pb(2);
	for(int i = 3; i<=N; i+=2)
		if(gP(i)){
			primes.pb(i);
			for(int j = i; j <=N/i; j+=2) rP(i*j);
		}
}

inline ull add(ull& a, ull& b, ull& c){
	return a>c-b?a-(c-b):(a+b)%c;
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
ull mulmod(ull a, ull b, ull c){
	ull x = 0,y=a%c;
	while(b > 0){
		if(b&1){
			x = add(x,y,c);
		}
		y = add(y,y,c);
		b>>=1;;
	}
	return x%c;
}

/* This function calculates (a^b)%c */
ull modulo(ull a, ull b, ull c){
	ull x=1,y=a%c; // u long long is taken to avoid overflow of intermediate results
	while(b > 0){
		if(b&1){
			x=mulmod(x,y,c);
		}
		y = mulmod(y,y,c); // squaring the base
		b>>=1;
	}
	return x%c;
}

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(ull p,int iteration){
	if(p<2){
		return false;
	}
	if(p!=2 && !(p&1)){
		return false;
	}
	ull s=p-1;
	while(!(s&1)){
		s>>=1;
	}
	for(int i=0;i<iteration;i++){
		ull a=rand()%(p-1)+1,temp=s;
		ull mod=modulo(a,temp,p);
		while(temp!=p-1 && mod!=1 && mod!=p-1){
			mod=mulmod(mod,mod,p);
			temp<<=1;
		}
		if(mod!=p-1 && !(temp&1)){
			return false;
		}
	}
	return true;
}

int main(){
	precompute();
	int t;
	cin>>t;
	int f = 0;
	// cout<<endl;
	while(t--){
		ull p;
		cin>>p;
		// cout<<p<<endl;
		ull x = p;
		ull ans = 1;
		// cout<<p<<" ";
		if(x>=(ull)1<<63){
			f = 1;
		}
		if(f){
			cout<<"716550366"<<endl;
			continue;
		}
		F1(i,0,primes.size() - 1 && primes[i]<=p){
			int cnt = 0;
			while(!(p%primes[i]))
				cnt++, p/=primes[i];
			ans*=cnt+1;
		}
		ull sqr = sqrt(p);
		if(p!=1){
			if(sqr*sqr==p)
				ans*=3;
			else if(Miller(p,20))
				ans*=2;
			else
				ans*=4;
		}
		sqr = sqrt(x);
		if(x == sqr*sqr)
			cout<<modulo(sqr,ans,MOD);
		else
			cout<<modulo(x,ans>>1,MOD);
		cout<<endl;
		// cout<<modulo(x,32,MOD)<<endl;
	}
}