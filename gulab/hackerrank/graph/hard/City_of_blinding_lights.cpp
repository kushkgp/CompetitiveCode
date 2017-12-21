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

void dijkstra(int st, int n, vector<map<int,int> > & adj, vi & dist){
	dist[st]=0;
	set<pii> s;
	s.insert(mp(0,st));
	while(!s.empty()){
		pii x = *s.begin();
		s.erase(s.begin());
		int u = x.ss, d = x.ff;
		for(auto & it : adj[u])
		{
			int v = it.ff,w = it.ss;
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
	int n, m;
	cin>>n>>m;
	vector<map<int,int> > adj(n);
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[--u][--v] = w;
	}
	vvi dist(n,vi(n,-1));
	for(int i = 0; i < n; i++)
		dijkstra(i,n,adj,dist[i]);
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<dist[--a][--b]<<endl;
	}
}