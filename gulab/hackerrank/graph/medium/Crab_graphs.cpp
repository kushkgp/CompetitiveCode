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

int find_path_bfs(int s, int t, vector<vpii> & adj){
	int n = adj.size();
	vi vis(n,0);
	vi flow(n,inf);				// stores the flow of path from s if visited
	vi parent(n,-1);			// required for updating the weights in augmentating path
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		bool path_found = false;		
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, c = adj[u][i].ss;
			if(!vis[v] && adj[u][i].ss){
				q.push(v);
				vis[v] = 1;
				parent[v] = u;
				flow[v] = min(flow[u],c);
				if(v==t){
					path_found = true;
					break;
				}
			}
		}
		if(path_found)
			break;
	}
	if(!vis[t])
		return 0;
	// update residual graph(adjacency list)
	int v = t;
	while(parent[v]!=-1){
		int u = parent[v];
		for(int i = 0; i < adj[u].size(); i++){
			if(adj[u][i].ff==v){
				adj[u][i].ss-=flow[t];
				break;
			}
		}
		for(int i = 0; i < adj[v].size(); i++){
			if(adj[v][i].ff==u){
				adj[v][i].ss+=flow[t];
				break;
			}
		}
		v = u;
	}
	return flow[t];
}

// to find actual flows pass copy of adj and compare it with original
int max_flow(int s, int t, vector<vpii> & adj){
	int result = 0, capacity;
	while((capacity=find_path_bfs(s,t,adj)))
		result+=capacity;
	return result;
}

int main(){
	BOOST;
	int c;
	cin>>c;
	while(c--){
		int n,t,m;
		cin>>n>>t>>m;
		vector<vpii> adj(2*n+2);
		for(int i = 0; i < m; i++){
			int u,v;
			cin>>u>>v;
			--u,--v;
			adj[2*u].pb(mp(2*v+1,1));
			adj[2*v+1].pb(mp(2*u,0));

			adj[2*v].pb(mp(2*u+1,1));
			adj[2*u+1].pb(mp(2*v,0));

		}
		for (int u = 0; u < n; u++)
		{
			adj[2*u+1].pb(mp(2*n+1,1));
			adj[2*n+1].pb(mp(2*u+1,0));
			
			adj[2*n].pb(mp(2*u,t));
			adj[2*u].pb(mp(2*n,0));
		}
		cout<<max_flow(2*n,2*n+1,adj)<<endl;
	}
}