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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll power(ll a, ll b){
	ll ans = 1;
	while(b>0){
		if(b&1)
			ans*=a;
		a = (a*a)%MOD;
		b>>=1;
		ans%=MOD;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	int cnt = 1;
	ll inv3 = power(3,MOD-2);
	while(t--){
		int r, c; 
		cin>>r>>c;
		ll ans;
		ll x = min(r,c) - 1;
		ans = x;
		ans*=x+1;
		ans>>=1;
		ans%=MOD;
		ans = (ans*ans)%MOD+(((ans*r)%MOD)*c)%MOD-(((((ans*(x*2+1))%MOD)*inv3)%MOD)*(r+c))%MOD+MOD;
		ans%=MOD;
		printf("Case #%d: %lld\n", cnt++, ans);
	}
}