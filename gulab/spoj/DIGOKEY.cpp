#include <bits/stdc++.h>
#define pb push_back
#define pf pop_front
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vv<int> adj(n);
		for(int i = 0; i < n - 1; i++){
			int m;
			cin>>m;
			for(int j = 0; j < m; j++){
				int x;
				cin>>x;
				adj[i].pb(--x);
			}
			sort(adj[i].begin(), adj[i].end());
		}
		v<int> p(n, -1);
		v<int> dis(n, 0);
		dis[0] = 1;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == n-1)
				break;
			for(int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i];
				if(!dis[v]){
					q.push(v);
					p[v] = u;
					dis[v] = 1;
				}
			}
		}
		if(p[n-1] != -1){
			int u = n - 1;
			stack<int> s;
			int ans = 0;
			while(p[u] != -1){
				int v = p[u];
				s.push(v);
				u = v;
				ans++;
			}
			cout<<ans<<endl;
			while(!s.empty()){
				cout<<s.top() + 1<<" ";
				s.pop();
			}
			cout<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
}