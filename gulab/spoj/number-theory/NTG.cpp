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
int phi[100001];
ll ans[100001];
ll k_pow[100001];
int k;

ll power(ll a, int b){
	if(!b)
		return 1;
	ll x = power(a,b>>1);
	x*=x;
	x%=MOD;
	if(b&1){
		x*=a;
		x%=MOD;
	}
	return x;
}

void precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,N){
		if(!phi[i]){
			phi[i] = i-1;
			for(int j = i; j<=N/i; j++)
				phi[i*j] = i;
		}
		else{
			int t = i/phi[i];
			while(!(t%phi[i]))
				t/=phi[i];
			if(t!=1)
				phi[i] = phi[t]*phi[i/t];
			else
				phi[i]*=phi[i/phi[i]];
		}
	}
	F1(i,1,N)
		k_pow[i] = power(i,k);

	fill(begin(ans),end(ans),0);
	ans[1] = 1;
	F1(i,2,N){
		for(int j = 1; j<=N/i; j++){
			ans[j*i]+=k_pow[j]*phi[i];
			ans[j*i]%=MOD;
		}
		ans[i]+=ans[i-1];
		ans[i]+=k_pow[i];
		ans[i]%=MOD;
	}
}

int main(){
	int t;
	cin>>k>>t;
	precompute();
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<(ans[r]-ans[l-1]+MOD)%MOD<<endl;
	}
}