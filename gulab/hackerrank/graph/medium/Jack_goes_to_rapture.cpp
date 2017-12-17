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

void prim(int start, vector<vpii> & adj,vi & dist){
	dist[start] = 0;
	set<pii> s;
	s.insert(mp(0,start));
	while(!s.empty()){
		pii x = *s.begin();
		s.erase(s.begin());
		int u = x.ss;
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if(max(dist[u],w)<dist[v]){
				if(s.find(mp(dist[v],v))!=s.end())
					s.erase(s.find(mp(dist[v],v)));
				dist[v] = max(dist[u],w);
				s.insert(mp(dist[v],v));
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vpii> adj(n);
	for(int i = 0; i < m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[--u].pb(mp(--v,c));
		adj[v].pb(mp(u,c));
	}
	vi dist(n,inf);
	prim(0,adj,dist);
	if(dist[n-1]!=inf)
		cout<<dist[n-1]<<endl;
	else
		cout<<"NO PATH EXISTS"<<endl;
}