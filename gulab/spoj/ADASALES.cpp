#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
using ll =  long long;

v<int> vis;
v<ll> f, g, c;
vv<int> adj;

void dfs1(int u){
	vis[u] = 1;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs1(v);
			f[u] = max(f[u], f[v] + max(0ll, c[v] - c[u]));
		}
	}
}

void dfs2(int u){
	vis[u] = 1;
	v<pair<int, ll> > child;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v])
			child.pb(mp(v, f[v] + max(0ll, c[v] - c[u]) ));
	}
	ll m = g[u];
	for(int i = 0; i < child.size(); i++){
		int v = child[i].ff;
		g[v] = max(g[v], m + max(0ll, c[u] - c[v]));
		m = max(m, child[i].ss);
	}
	m = g[u];
	for(int i = child.size() -1; i >= 0; i--){
		int v = child[i].ff;
		g[v] = max(g[v], m + max(0ll, c[u] - c[v]));
		m = max(m, child[i].ss);
	}
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v])
			dfs2(v);
	}
}

int main(){
	int n, q;
	cin>>n>>q;
	c.resize(n, 0);
	vis.resize(n, 0);
	for(int i = 0; i < n; i++){
		cin>>c[i];
	}
	adj.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	f.resize(n, 0);
	dfs1(0);
	vis.clear();
	vis.resize(n, 0);
	g.resize(n, 0);
	dfs2(0);
	while(q--){
		int x;
		cin>>x;
		cout<<max(f[x], g[x])<<endl;
	}
	return 0;
}
