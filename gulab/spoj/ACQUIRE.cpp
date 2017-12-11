/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

bool compare(const pii &a, const pii & b){
	if(a.ff==b.ff)
		return a.ss<b.ss;
	return a.ff>b.ff;
}

class conhull{
private:
	vector<pair<int,ll> > v;
	float intersection(int m1, int m2, ll c1, ll c2){		// intersection point x coordinate
		return (float(c1-c2))/(m2-m1);
	}
	float intersection(pair<int,ll> a, pair<int,ll> b){
		return intersection(a.ff,b.ff,a.ss,b.ss);
	}
	int bs(float key){										// bs for index of required line
		int x=v.size()-1;							// intialising result to n-1 the line
		int mid,l=0,r=x-1;							// checking only on lines 0 to n-2
		while(l<=r){
			mid=(l+r)/2;
			if(intersection(v[mid],v[mid+1])>=key){	// if key(x coordinate) <= x coordinate of intersection(mid,mid+1)
				x=mid;								// current line is mid
				r=mid-1;							// search left
			}
			else
				l=mid+1;							// search right
		}
		return x;
	}
public:
	const vector<pair<int,ll> > & get_vector() const {
		return v;
	}
	void add(int m, ll c){							// delete redundant lines and then add this line
		for (int i = v.size()-1; i >=1; --i)
		{
			if(intersection(v[i],v[i-1])>=intersection(v[i-1].ff,m,v[i-1].ss,c)){
				v.pop_back();						// pop like stack
			}
			else break;
		}
		v.pb(mp(m,c));								// add line to hull
	}
	ll query(ll x){
		int index = bs(x);
		return x*v[index].ff+v[index].ss;			// line equation (m*x+c)
	}
};

/*

*/

ll ans(vpii &v, int n){
	sort(all(v),compare);
	ll result=0;
	vpii a;
	int j=1;
	a.pb(v[0]);
	for (int i = 0;j<n;j++)
	{
		if(v[i].ss<=v[j].ss){
			a.pb(v[j]);
			i=j;
		}
	}
	ll dp=0;
	conhull E;
	for (int i = 0; i < a.size(); ++i)
	{
		E.add(a[i].ff,dp);
		dp = E.query(a[i].ss);
	}
	return dp;
}
ll ans_dp(vpii &v, int n){
	sort(all(v),compare);
	ll result=0;
	vpii a;
	int j=1;
	a.pb(v[0]);
	for (int i = 0;j<n;j++)
	{
		if(v[i].ss<=v[j].ss){
			a.pb(v[j]);
			i=j;
		}
	}
	ll dp[a.size()+1];
	dp[0]=0;
	for (int i = 1; i <= a.size(); ++i)
	{
		dp[i] = LONG_MAX;
		for (int j = 0; j < i; j++)
			dp[i] = min(dp[i],dp[j] + (ll)a[i-1].ss*a[j].ff);
	}
	return dp[a.size()];
}

int main(){
	int n;
	cin>>n;
	vpii v(n);
	FOR(i,n)
		cin>>v[i].ff>>v[i].ss;
	cout<<ans(v,n)<<endl;
	return 0;
}