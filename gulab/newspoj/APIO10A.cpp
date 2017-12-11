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
typedef pair<int,ll> pill;
typedef vector<pii> vpii;


class conhull{
private:
	vector<pair<int,ll> > v;					/* Vector for storing lines */

	/* intersection point x coordinate */
	float intersection(int m1, int m2, ll c1, ll c2){
		return (float(c1-c2))/(m2-m1);
	}
	float intersection(pair<int,ll> a, pair<int,ll> b){
		return intersection(a.ff,b.ff,a.ss,b.ss);
	}
	/* bs for index of required line */
	int bs(float key){
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
	/* Deletes redundant lines(now) and then add this line */
	void add(int m, ll c){
		for (int i = v.size()-1; i >=1; --i)
		{
			if(intersection(v[i],v[i-1])>=intersection(v[i-1].ff,m,v[i-1].ss,c)){
				v.pop_back();						// pop like stack
			}
			else break;
		}
		v.pb(mp(m,c));								// add line to hull
	}
	/* For random query */
	ll query(ll x){
		int index = bs(x);
		return x*v[index].ff+v[index].ss;			// line equation
	}
	/* Pointer walk(changes index accordingly) : Use when x is increasing */
	ll query(ll x, int &index){		
		if(index>v.size()-1)						// if index > last_index previous lines deleted some lines change it to last index										
			index = v.size()-1;
		for (; index<v.size()-1; ++index)			// increase index till intersection(index,index+1)>=x
		{
			if(intersection(v[index],v[index+1])<x)
				continue;
			break;
		}
		return x*v[index].ff+v[index].ss;			// line equation
	}
};


ll ans(vi &v, ll a, ll b, ll c){
	for (int i = 1; i < v.size(); ++i){
		v[i]+=v[i-1];
	}
	ll dp=0;
	conhull E;
	int ind = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		E.add(-2*a*v[i-1],dp + a*v[i-1]*v[i-1] - b*v[i-1]);
		dp = E.query(v[i],ind) + a*v[i]*v[i] + b*v[i]+c;
	}
	return dp;
}

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a,b,c;
		cin>>a>>b>>c;
		vi v;
		v.resize(n+1);
		v[0]=0;
		for (int i = 1; i <= n; ++i)
			cin>>v[i];
		cout<<ans(v,a,b,c)<<endl;
	}
}