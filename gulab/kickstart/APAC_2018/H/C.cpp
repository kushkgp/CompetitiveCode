/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
// #define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007
#define print(test_case, ans) cout << "Case #" << test_case << ": " << ans << "\n"

using namespace std;
typedef long long int ll;
template <typename x> using v = vector<x>;
template <typename x> using vv = v<v<x> >;

ll pow(int a, int p, int m){
	if(!p)
		return 1%m;
	ll x = pow(a, p>>1, m);
	x*=x;
	x%=m;
	x*=(p&1?a:1);
	return x%m;
}

int N = 2e5;

v<ll> f(N+1);
v<ll> inf(N+1);

void preprocess(){
	f[0] = inf[0] = 1;
	F1(i, 1, N){
		f[i]=i*f[i-1];
		f[i]%=MOD;
		inf[i]=pow(i, MOD-2, MOD)*inf[i-1];
		inf[i]%=MOD;
	}
}

int main(){
	preprocess();
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int m1 = 1;
		ll sum = 0;
		ll p2 = 1;
		F1(i, 0, m){
			ll temp = m1;
			temp*=(f[m]*inf[i])%MOD;
			temp=(temp*inf[m-i])%MOD;
			temp=(temp*p2)%MOD;
			temp=(temp*f[2*n-i])%MOD;
			sum+=temp;
			sum%=MOD;
			m1*=-1;
			p2<<=1;
			p2%=MOD;
		}
		print(cnt++, (sum+MOD)%MOD);
	}
}