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

void dijkstra(int src, int time, map<pii,map<pii,int> > & adj, vvi & d){
	set<pair<int,pii> > s;
	d[src][time]=0;
	s.insert(mp(0,mp(src,time)));
	int tot=0;
	while(!s.empty()){
		int x = s.begin()->ff;
		pii u = s.begin()->ss;
		s.erase(s.begin());
		for(auto & it : adj[u]){
			pii v = it.ff;
			int w = it.ss;
			d[v.ff][v.ss];
			if((d[v.ff][v.ss]==-1) || x+w<d[v.ff][v.ss]){
				s.erase(mp(d[v.ff][v.ss],v));
				d[v.ff][v.ss] = x+w;
				s.insert(mp(d[v.ff][v.ss],v));
			}
		}
	}
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		map<pii,map<pii,int> > adj;
		for(int i = 0; i < m; i++){
			int a,b;
			cin>>a>>b;
			--a,--b;
			for(int j = 0; j < 24; j++){
				int x;
				cin>>x;
				int y = (j+x)%24;
				pii u = mp(a,j),v = mp(b,y);
				if(adj[u].find(v)==adj[u].end() || adj[u][v]>x)
					adj[u][v] = x;

				u = mp(b,j), v = mp(a,y);
				if(adj[u].find(v)==adj[u].end() || adj[u][v]>x)
					adj[u][v] = x;
			}
		}
		vector<vvi> d(24,vvi(n,vi(24,-1)));
		for(int i = 0; i < 24; i++)
			dijkstra(0,i,adj,d[i]);
		printf("Case #%d: ", cnt++);
		while(k--){
			int s,t;
			cin>>s>>t;
			s--;
			int ans=-1;
			for(int i = 0; i < 24; i++)
				if(d[t][s][i]!=-1)
					ans = (ans==-1)?d[t][s][i]:min(ans,d[t][s][i]);
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}