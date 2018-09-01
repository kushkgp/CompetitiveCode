#include <bits/stdc++.h>
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
v<int> vis, instack;
v<int> dis;
v<int> low;
v<int> ans;
vv<int> adj;
vv<int> radj;

void dfs(int u, int &t, stack<int> &s){
	vis[u] = 1;
	instack[u] = 1;
	dis[u] = low[u] = t++;
	s.push(u);
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v, t, s);
			if(ans.size())
				return;
			low[u] = min(low[u], low[v]);
		}
		else if(instack[v]){
			low[u] = min(low[u], dis[v]);
		}
	}

	if(dis[u] == low[u] && !ans.size()){
		// ans.clear();
		while(!s.empty()){
			int v = s.top();
			s.pop();
			instack[v] = 0;
			ans.pb(v);
			if(v == u)
				break;
		}
	}
	return ;
}

void dfs1(int u, v<int> & vis){
	vis[u] = 1;
	for(int i = 0; i < radj[u].size(); i++){
		int v = radj[u][i];
		if(!vis[v])
			dfs1(v, vis);
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	adj.resize(n);
	radj.resize(n);
	for(int i = 0; i < m; i++){
		int x, y;
		cin>>x>>y;
		adj[--x].pb(--y);
		radj[y].pb(x);
	}
	vis.resize(n, 0);
	dis.resize(n);
	instack.resize(n, 0);
	low.resize(n);
	stack<int> s;
	int t = 0;
	dfs(0, t, s);
	sort(ans.begin(), ans.end());
	if(ans.size()){
		for(int i = 0; i < vis.size(); i++)
			vis[i] = 0;
		dfs1(ans[0], vis);
		int f = 1;
		for(int i = 0; i < vis.size(); i++)
			if(!vis[i])
				f = 0;

		if(f){
			cout<<ans.size()<<endl;
			for(int i = 0; i < ans.size(); i++)
				cout<<ans[i]+1<<" ";
			cout<<endl;
		}
		else
			cout<<0<<endl;
	}
	else
		cout<<0<<endl;
	return 0;
}