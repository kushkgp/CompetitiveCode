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
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

ll turan(int n, int r){
	ll m = (ll)n*n;
	int x1 = ceil((double)n/r);
	int x2 = floor((double)n/r);
	m-=(ll)(n%r)*x1*x1;
	m-=(ll)(r-n%r)*x2*x2;
	m=m>>1;
	return m;
}

int bs(int n, ll m){
	int l = 2, r = n;
	int ans=1;
	while(l<=r){
		int mid = (l+r)/2;
		if(m>=turan(n,mid-1)+1){
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	BOOST;
	while(t--){
		int n;
		cin>>n;
		ll m;
		cin>>m;
		cout<<bs(n,m)<<endl;
	}
}