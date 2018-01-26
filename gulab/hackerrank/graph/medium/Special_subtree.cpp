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

int prim(int start, vector<vpii> & adj, vi & dist, vi & vis){
	dist[start] = 0;
	set<pii> s;
	s.insert(mp(0,start));
	int ans = 0;
	while(!s.empty()){
		pii x = *s.begin();
		s.erase(s.begin());
		int u = x.ss;
		ans+=x.ff;
		vis[u] = 1;
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if(!vis[v] && dist[v]>w){
				if(s.find(mp(dist[v],v))!=s.end())
					s.erase(s.find(mp(dist[v],v)));
				dist[v] = w;
				s.insert(mp(dist[v],v));
			}
		}
	}
	return ans;
}

int main(){
	BOOST;
	int n,m;
	cin>>n>>m;
	vector<vpii> adj(n);
	vi dist(n,inf);
	vi vis(n,0);
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[--u].pb(mp(--v,w));
		adj[v].pb(mp(u,w));
	}
	int s;
	cin>>s;
	cout<<prim(--s,adj,dist,vis)<<endl;
}