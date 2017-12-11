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
typedef vector<pill> vpill;
typedef vector<ll> vll;
#define MAAAX 100002

ll g[MAAAX];
vpill bh;
vpill ah;
vvi a,b;
int t,n1,n2;

ll dfs(int u, vvi & adj, int len, vpill& hash){
	if(adj[u].size()==0){
		hash[u] = mp(0,g[0]);
		return g[0];
	}
	vll temp;
	tr(adj[u],it){
		temp.pb(dfs(*it,adj,len,hash));
	}
	asort(temp);
	ll ans = g[0];
	FOR(i,temp.size()){
		ans^=temp[i]*g[i+1];
	}
	hash[u]=mp(temp.size(),ans); 
	return ans;
}

void dfs1(int u, ll cum_hash, int level, set< pair<int,ll> > &s){
	if(a[u].size()==0){
		s.insert(mp(level,cum_hash));
		return;
	}
	cum_hash^=g[level]*ah[u].ss;
	tr(a[u],it){
		dfs1(*it,cum_hash,level+1,s);
	}	
}

int main(){
	BOOST;
	FOR(i,MAAAX){
		g[i] = rand();
	}
	cin>>t;
	while(t--){
		cin>>n1>>n2;
		a.clear();b.clear();ah.clear();bh.clear();
		a.resize(n1);ah.resize(n1);
		b.resize(n2);bh.resize(n2);
		FOR(i,n1){
			if(!i) continue;
			int x;
			cin>>x;
			a[x-1].pb(i);
		}
		FOR(i,n2){
			if(!i) continue;
			int x;
			cin>>x;
			b[x-1].pb(i);
		}
		dfs(0,a,n1,ah);
		dfs(0,b,n2,bh);
		set< pair<int,ll> > s1;
		dfs1(0,0,0,s1);
		set< pair<int,ll> > s2;
		tr(bh,it){
			s2.insert(*it);
		}
		ll ans  = (ll)s1.size()*s2.size();
		cout<<ans<<endl;
	}
	return 0;
}