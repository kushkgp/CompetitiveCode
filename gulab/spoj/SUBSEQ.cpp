/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <unordered_map>
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

int main(){
	BOOST;
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int v;
		unordered_map<int,ll> m;
		m.insert(mp(0,1));
		ll sum = 0;
		ll result = 0;
		for (int i = 0; i < n; ++i){
			cin>>v;
			sum+=v;
			if(present(m,sum-47))
				result += m[sum-47];
			if(present(m,sum))
				m[sum]++;
			else m.insert(mp(sum,1));
		}
		cout<<result<<endl;
	}
}