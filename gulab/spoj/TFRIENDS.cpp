#include <bits/stdc++.h>
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;

int dfs(int u, v<int> & vis, v<int> & dis, v<int> & low, vv<int> & adj, v<int> & instack, stack<int> & s,int & time){
	vis[u] = 1;
	instack[u] = 1;
	dis[u] = low[u] = time++;
	s.push(u);
	int ans = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			ans+=dfs(v, vis, dis, low, adj, instack, s, time);
			low[u] = min(low[u], low[v]);
		}
		else if(instack[v]){
			low[u] = min(low[u], dis[v]);
		}
	}
	if(low[u] == dis[u]){
		ans++;
		while(!s.empty()){
			int v = s.top();
			instack[v] = 0;
			s.pop();
			if(v == u)
				break;
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vv<int> adj(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				char c;
				cin>>c;
				if(c == 'Y')
					adj[i].pb(j);
			}
		}
		int ans = 0;
		v<int> vis(n, 0);
		v<int> instack(n, 0);
		v<int> dis(n, -1);
		v<int> low(n, INT_MAX);
		int time = 0;
		stack<int> s;
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				ans+=dfs(i, vis, dis, low, adj, instack, s, time);
			}
		}
		cout<<ans<<endl;
	}
}