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

void bfs(int start, vector<vpii> & adj, vvi & vis){
	vis[start][0] = 1;
	queue<pii> q;
	q.push(mp(start,0));
	while(!q.empty()){
		pii x = q.front();
		q.pop();
		int u = x.ff, d = x.ss;
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if(!vis[v][d|w]){
				vis[v][d|w]=1;
				q.push(mp(v,d|w));
			}
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<vpii> adj(n);
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[--u].pb(mp(--v,w));
		adj[v].pb(mp(u,w));
	}
	int a,b;
	cin>>a>>b;
	--a,--b;
	vvi vis(n,vi(1<<10,0));
	bfs(a,adj,vis);
	for(int i = 0; i < (1<<10); i++){
		if(vis[b][i]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}