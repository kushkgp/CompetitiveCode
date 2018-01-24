/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

void dijkstra(int n, vector<vpii> & adj, vvi & dist, vi & mask){
	set<pair<int, pii> > s;
	dist[0][mask[0]] = 0;

	s.insert(mp(0,mp(0,mask[0])));
	while(!s.empty()){
		pair<int, pii> x = *s.begin();
		s.erase(s.begin());
		int d = x.ff, u = x.ss.ff, m = x.ss.ss;
		for(int i = 0; i<adj[u].size(); i++){
			int v = adj[u][i].ff,c = adj[u][i].ss;
			pii state = mp(v,mask[v]|m);
			if(d+c<dist[v][mask[v]|m]){
				pair<int, pii> temp_key = mp(dist[v][mask[v]|m],state);
				if(present(s,temp_key)){
					s.erase(s.find(temp_key));
				}
				dist[v][mask[v]|m] = d+c;
				temp_key = mp(dist[v][mask[v]|m],state);
				s.insert(temp_key);
			}
		}
	}
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	BOOST;
	vi mask(n,0);
	vector<vpii> adj(n);
	for(int i = 0; i<n; i++){
		int t;
		cin>>t;
		while(t--){
			int a;
			cin>>a;
			mask[i] |= 1<<(a-1);
		}
	}
	for(int i = 0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		--x,--y;
		adj[x].pb(mp(y,z));
		adj[y].pb(mp(x,z));
	}
	vvi dist(n,vi(1<<k,inf));
	dijkstra(n,adj,dist,mask);
	int ans = inf;
	for(int i = 0; i < 1<<k; i++){
		for(int j = 0; j < 1<<k; j++){
			if((i|j)==(1<<k)-1)
				ans = min(ans,max(dist[n-1][i],dist[n-1][j]));
		}
	}
	cout<<ans<<endl;
	return 0;
}