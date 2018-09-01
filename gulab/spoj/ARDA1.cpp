#include <bits/stdc++.h>
#define pr1 29
#define pr2 31
#define pr3 37
#define pr4 41
using namespace std;


ll pow(int a, int p, int m){
	if(!p)
		return 1%m;
	ll x = pow(a, p>>1, m);
	x*=x;
	x%=m;
	x*=(p&1?a:1);
	return x%m;
}

int main(){
	int n1, n2;
	cin>>n1>>n2;
	v<string> p(n1);
	for(int i = 0; i < n1; i++)
		cin>>p[i];
	int m1, m2;
	cin>>m1>>m2;
	v<string> s(m1);
	for(int i = 0; i < m1; i++)
		cin>>s[i];
	if(m1 < n1 || m2 < n2){
		cout<<"NO MATCH FOUND"<<endl;
		return 0;
	}
	vv<int> p1(m1, v<int>(m2, 0));
	vv<int> p2(m1, v<int>(m2, 0));
	v<int> invp1(m2, 0);
	v<int> invp2(m2, 0);

	for(int i = 0; i < m1; i++){
		ll a  = 1, b = 1;
		for(int j = 0; j < m2; j++){
			p1[i][j] = (a*(s[i][j]- 'a'+1))%mod;
			p2[i][j] = (b*(s[i][j]- 'a'+1))%mod;
			if(i){
				p1[i][j]+=p1[i-1][j];
				p1[i][j]%=mod;
				p2[i][j]+=p2[i-1][j];
				p2[i][j]%=mod;
			}
			a*=pr1, b*=pr2;
		}
	}

	pair<ll, ll> h = mp(0ll, 0ll);
	ll c = 1;
	for(int i = 0; i < n1; i++){
		ll a = 1, b = 1;
		ll x = 0, y = 0;
		for(int j = 0; j < n2; j++){
			x += (a*(p[i] - 'a' + 1))%mod;
			y += (b*(p[i] - 'a' + 1))%mod;
			a*=pr1, b*=pr2;
		}
		x%=mod;
		y%=mod;
		h.ff += (x*c)%mod;
		h.ss += (y*c)%mod;
		c*=pr3;
	}
	h.ff%=mod;
	h.ss%=mod;

	vv<pair<ll,ll> > hashes(m1 - n1 + 1, v<pair<ll,ll> >(m2 - n2 + 1, mp(0ll, 0ll)));
	for(int i = 0; i < m1 - n1 + 1; i++){
		ll c = pr3;
		ll invc = pow(c, mod - 2, mod );
		ll curr1 = 0, curr2 = 0;
		for(int j = 0; j < m2 - n2 + 1; j++){
			if(j>=m2){
				curr1 -= ((p1[i+m1][j-m2] - p1[i][j-m2] + mod)%mod)*;
				curr1 += mod;
				curr1 %= mod;
			}

			curr1*=invc, curr2*=invc;
			curr1%=mod, curr2%=mod;

			curr1 += (c*(*(p1[i+m1][j]))%mod)%mod;

			if(j>=m2-1){
				hashes[i][j-m2+1] = mp(curr1, curr2);
			}
			else{
				c*=pr3;
				c%=mod;
			}
		}
	}

	for(int i = 0; i < hashes.size(); i++){
		for(int j = 0; j < hashes[0].size(); j++){
			if(hash == hashes[i][j])
				cout<<"("<<i+1<<","<<j+1<<")"<<endl;
		}
	}
	return 0;
}	