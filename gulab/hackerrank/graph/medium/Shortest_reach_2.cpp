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

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

void dijkstra(int start, vector<vpii> & adj, vi & dist){
	dist[start] = 0;
	set<pii> s;
	s.insert(mp(0,start));
	while(!s.empty()){
		pii x = *s.begin();
		int u = x.ss, d = x.ff;
		s.erase(s.begin());
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if(dist[v]==-1 || dist[v]>d+w){
				if(s.find(mp(dist[v],v))!=s.end())
					s.erase(s.find(mp(dist[v],v)));
				dist[v] = d+w;
				s.insert(mp(dist[v],v));
			}
		}
	}
}

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		map<pii,int> M;		
		for(int i = 0; i < m; i++){
			int u,v,w;
			cin>>u>>v>>w;
			--u,--v;
			if(u>v)
				swap(u,v);
			if(M.find(mp(u,v))!=M.end() && M[mp(u,v)]>w){
				M[mp(u,v)]=w;
			}
			else
				M.insert(mp(mp(u,v),w));
		}
		int s;
		cin>>s;
		vector<vpii> adj(n);
		vi vis(n,-1);
		for(const auto & it : M){
			adj[it.ff.ff].pb(mp(it.ff.ss,it.ss));
			adj[it.ff.ss].pb(mp(it.ff.ff,it.ss));
		}
		dijkstra(--s,adj,vis);
		for(int i = 0; i < n; i++){
			if(i!=s){
				cout<<vis[i]<<" ";
			}
		}
		cout<<endl;
	}
}