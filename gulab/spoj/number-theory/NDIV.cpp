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
int a,b,ans,x;

void precompute(){
	int n = sqrt(b)+1;
	vi phi(n+1,0);
	vi primes;
	for(int i = 2; (ll)i*i<=b; i++){
		if(!phi[i]){
			primes.pb(i);
			for(int j = i; (ll)j*i<=n; j++){
				phi[j*i] = 1;
			}
		}
	}
	F1(i,0,(b-a)){
		int val = 1;
		int y = i+a;
		F1(j,0,(int)primes.size()-1){
			int cnt = 1;
			while(!(y%primes[j]))
				cnt++,y/=primes[j];
			val*=cnt;
		}
		if(y!=1)
			val*=2;
		if(val == x){
			// cout<<i+a<<endl;
			ans++;
		}
	}
}

int main(){
	cin>>a>>b>>x;
	precompute();
	cout<<ans<<endl;
}