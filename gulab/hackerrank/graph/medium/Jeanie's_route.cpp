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
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

int dfs(int u, int n, vector<vpii> & adj, vi & vis, vi & scity, vi & kcity){
	vis[u] = 1;
	int ans = 0;
	scity[u] = kcity[u];
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i].ff, w = adj[u][i].ss;
		if(!vis[v]){
			ans += dfs(v,n,adj,vis,scity,kcity);
			if(scity[v])
				ans+=w;
			scity[u]|=scity[v];
		}
	}
	return ans;
}

pii dfs1(int u, int n, vector<vpii> & adj, vi & vis, vi & scity){
	vis[u] = 1;
	int ans = 0,node=u;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i].ff, w = adj[u][i].ss;
		if(!vis[v] && scity[v]){
			pii x = dfs1(v,n,adj,vis,scity);
			if(ans<x.ff+w){
				ans = x.ff+w;
				node = x.ss;
			}
		}
	}
	return mp(ans,node);
}

int main(){
	int n,k;
	cin>>n>>k;
	vi scity(n,0);
	vi kcity(n,0);
	int x;
	for(int i = 0; i < k; i++){
		cin>>x;
		scity[--x] = 1;
		kcity[x] = 1;
	}
	vector<vpii> adj(n);
	for(int i = 0; i < n-1; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[--u].pb(mp(--v,w));
		adj[v].pb(mp(u,w));
	}
	vi vis(n,0);
	int mst = dfs(x,n,adj,vis,scity,kcity);
	fill(all(vis),0);
	x = dfs1(x,n,adj,vis,scity).ss;
	fill(all(vis),0);
	int y = dfs1(x,n,adj,vis,scity).ff;
	cout<<2*mst-y<<endl;
}