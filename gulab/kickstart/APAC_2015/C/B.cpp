/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll bs(int p, ll k){
	ll l = 1, r = 1e15;
	ll x = -1;
	while(l<=r){
		ll mid = (l+r)>>1;
		if(floor((long double)k/mid)<=p){
			if(floor((long double)k/mid)==p)
				x = mid;
			r = mid-1;
		}
		else
			l = mid+1;
	}
	return x;
}

ll bs2(int p, ll k){
	ll l = 1, r = 1e15;
	ll x = 0;
	while(l<=r){
		ll mid = (l+r)>>1;
		if(floor((long double)k/mid)>=p){
			if(floor((long double)k/mid)==p)
				x = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	return x;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll l = 1, r = 1e15;
		for(int i = 0; i < n; i++){
			int p;
			ll k;
			cin>>p>>k;
			if(p==k && p==0)
				continue;
			k*=100;
			l = max(l,bs(p,k));
			r = min(r,bs2(p,k));
			if(p==100){
				l = r = k/100;
			}
		}
		printf("Case #%d: ", cnt++);
		if(l==r)
			cout<<l;
		else
			cout<<-1;
		cout<<endl;
	}
}