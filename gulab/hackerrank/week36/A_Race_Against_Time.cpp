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
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;

struct X{
	ll d,ind,cumm; 
	X(ll x, ll y, ll z):d(x),ind(y),cumm(z){}
	X(){}
};
typedef struct X dp;

int main(){
	int n;
	cin>>n;
	vi h(n);
	vi p(n);
	cin>>h[0];
	p[0] = 0;
	F1(i,1,n-1)
		cin>>h[i];
	F1(i,1,n-1)
		cin>>p[i];
	map<pii,dp> m;
	m[mp(h[0],0)] = dp(0,0,h[0]);
	F1(i,1,n-1){
		ll self = i+p[i];
		ll ans=1e18;
		ll d;
		while(m.begin()!=m.end() && m.begin()->ff.ff < h[i]){
			dp it = m.begin()->ss;
			m.erase(m.begin());
			ans = min(ans,it.d-it.ind-h[it.ind]+h[i]);
		}
		if(m.begin()!=m.end())
			ans = min(ans,m.begin()->ss.cumm-h[i]);
		d = self + ans;
		ll cumm = d-i+h[i];
		if(m.begin()!=m.end())
			cumm = min(cumm,m.begin()->ss.cumm);
		m[mp(h[i],-i)] = dp(d,i,cumm);
	}
	ll ans = 1e18;
	for(auto & it : m)
		ans = min(ans,it.ss.d-it.ss.ind+n);
	cout<<ans<<endl;
}