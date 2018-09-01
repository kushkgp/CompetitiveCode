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

ll f(vector<pair<int, pair<int,int> > > & m, ll mid){
	ll ans = 0;
	F1(i, 0, m.size()-1){
		ll x = (mid - m[i].ff)/m[i].ss.ff;
		x = x>=0?x:0;
		ans += min((ll)m[i].ss.ss,x);
	}
	return ans;
}

int bs(vector<pair<int, pair<int,int> > > & m, int b){
	if(!b)
		return 0;
	ll x=-1;
	ll mid,l=0,r=2e18;
	while(l<=r){
		mid=(l+r)/2;
		if(f(m,mid)>=b){
			x=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return x;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int r,b,c;
		cin>>r>>b>>c;
		// p, s, m
		r = min(r,c);
		vector<pair<int, pair<int,int> > > m(c);
		// cout<<"hi"<<endl;
		F1(i, 0, c-1){
			cin>>m[i].ss.ss>>m[i].ss.ff>>m[i].ff;
		}
		sort(all(m));
		printf("Case #%d: ", cnt++);
		cout<<bs(m,b)<<endl;
	}
}