/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define inf INT_MAX
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

// bfs implementation for augmentating path takes O(n+m) time
// Update step for path edges takes O(n^2) time, can be reduced to O(n) with extra memory
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
	// update residual graph(adjacency list), this part 
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

// To find actual flows pass copy of adj and compare it with original
// Always add edges in both direction with positive weights
// if graph is undirected add edges to both direction with given weight
// in case of undirected add forward edge with weight and backward with 0 
int max_flow(int s, int t, vector<vpii> & adj){
	int result = 0, capacity;
	while((capacity=find_path_bfs(s,t,adj)))
		result+=capacity;
	return result;
}

// required for min_cut
void dfs(int n, int u, vector<vpii> & adj, vector<vpii> & residual, vi & vis){
	vis[u] = 1;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[v][i].ff, w = adj[v][i].ss - residual[v][i].ss;
		if(!vis[v] && w)
			dfs(n,v,adj,residual,vis);
	}
}

// return min_cut and arbitary min cut as vector of edges
// change code if you want original weights with edges in the cut also
int min_cut(int s, int t, vector<vpii> & adj, vpii & cut){
	int n = adj.size();
	vector<vpii> residual = adj;
	max_flow(s,t,residual);
	vi vis(n,0);
	dfs(n,s,adj,residual,vis);
	for(int u = 0; u < n; u++){
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff;
			if(vis[u] && !vis[v])
				cut.push_back(mp(u,v));
		}
	}
}


// to be written https://www.topcoder.com/community/data-science/data-science-tutorials/maximum-flow-section-1/
/*int find_path_pfs(int s, int t, vector<vpii> & adj){
	vi vis(n,0);
	vi flow(n,inf);
	vi from(n,-1);
	
	// update residual graph
	int u = t;
	while(from[u]>-1){
		int v = from[u];
		for(int i = 0; i < adj[u][i].size(); i++){
			if(adj[u][i].ff==v){
				adj[u][i].ss+=flow[t];
				break;
			}
		}
		swap(u,v);
		for(int i = 0; i < adj[u][i].size(); i++){
			if(adj[u][i].ff==v){
				adj[u][i].ss-=flow[t];
				break;
			}
		}
	}

	if(vis[t])
		return flow[t];
	return 0;
}
*/