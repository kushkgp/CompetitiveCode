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


void dijkstra(vvi & d, map<pii,vector<pair<pii,int> > > & adj, pii src, pii tar){
	d[src.ff][src.ss]=0;
	set<pair<int,pii> > m;
	m.insert(mp(0,src));
	while(!m.empty()){
		pii u = m.begin()->ss;
		int x = m.begin()->ff;
		m.erase(m.begin());
		if(u==tar)
			return;
		for(int i = 0; i < adj[u].size(); i++){
			pii v = adj[u][i].ff;
			int w = adj[u][i].ss;
			if(d[v.ff][v.ss]==-1 || x+w<d[v.ff][v.ss]){
				m.erase(mp(d[v.ff][v.ss],v));
				d[v.ff][v.ss] = x+w;
				m.insert(mp(x+w,v));
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	int cnt = 1;
	while(t--){
		int n;
		cin>>n;
		vi w(n+1);
		vi s(n+1);
		map<pii,vector<pair<pii,int> > > adj;
		for(int i = 1; i <= n; i++){
			cin>>s[i]>>w[i];
			for(int j = 1; j < s[i]; j++){
				int x;
				cin>>x;
				adj[mp(i,2*j)].pb(mp(mp(i,2*(j+1)),x));
				adj[mp(i,2*(j+1))].pb(mp(mp(i,2*j),x));
			}
			for(int j = 1; j <= s[i]; j++){
				adj[mp(i,2*j)].pb(mp(mp(i,2*j+1),0));
				adj[mp(i,2*j+1)].pb(mp(mp(i,2*j),w[i]));
			}
		}
		int m;
		cin>>m;
		for(int i = 0; i < m; i++){
			int m1,m2,s1,s2,time;
			cin>>m1>>s1>>m2>>s2>>time;
			adj[mp(m1,2*s1+1)].pb(mp(mp(m2,2*s2+1),time));
			adj[mp(m2,2*s2+1)].pb(mp(mp(m1,2*s1+1),time));
		}
		printf("Case #%d:\n", cnt++);
		int q;
		cin>>q;
		while(q--){
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			vvi d(n+1);
			for(int i = 1; i <= n; i++)
				d[i].resize(2*(s[i]+1),-1);
			dijkstra(d,adj,mp(x1,2*y1+1),mp(x2,2*y2+1));
			cout<<d[x2][2*y2+1]<<endl;
		}
	}
}