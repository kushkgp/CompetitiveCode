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

#define N 1000000
int phi[1000001];
vi primes;

void precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,N){
		if(!phi[i]){
			primes.pb(i);
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = 1;
		}
	}
}


int main(){
	BOOST;
	precompute();
	int cnt = 1;
	while(1){
		int a,b;
		cin>>a>>b;
		if(!a)
			break;
		int dim = 0, d = 0;
		F1(i,0,primes.size()-1){
			int p = primes[i];
			int c1,c2;
			c1 = c2 = 0;
			while(!(a%p))
				c1++, a/=p;
			while(!(b%p))
				c2++, b/=p;
			if(c1||c2)
				dim++;
			d+=abs(c1-c2);
		}
		printf("%d. %d:%d\n", cnt++, dim, d);
	}
}