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

int main(){
	int n;
	cin>>n;
	vector<ll> v;
	v.resize(n);
	for (int i = n-1; i>=0; --i)
		cin>>v[i];
	for (int i = 1; i < n; ++i)
		v[i]+=v[i-1];
	int q;
	cin>>q;
	while(q--){
		int f;
		cin>>f;
		if(f==1){
			int l,r;
			cin>>l>>r;
			ll temp = v[n-l];
			if(r!=n)
				temp-=v[n-r-1];
			cout<<temp<<endl;
		}
		else{
			int x;
			cin>>x;
			v.pb(x);
			v[n]+= v[n-1];
			n++;
		}
	}
	return 0;
}