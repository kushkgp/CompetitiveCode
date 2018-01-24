/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

class Graph{
private:
	int V,E;
	vvi adj;
public:
	Graph(int x):V(x){
		adj.resize(V,vi());
	}
	void addEdge(int a, int b){
		adj[a].pb(b);
		adj[b].pb(a);
		E++;
	}
	int DFS(int u, int time, int low[], int disc[], int vis[],int parent[],set<pii> & bridge,int given){
		disc[u] = low[u] = time++;
		vis[u] = given;
		int x = 0;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if(!vis[v]){
				parent[v] = u;
				x+=DFS(v,time,low,disc,vis,parent,bridge,given);
				low[u] = min(low[u],low[v]);
				if (low[v] > disc[u]){
					bridge.insert(mp(min(u,v),max(u,v)));
					x++;
				}
			}
			else if(parent[u]!=v){
				low[u] = min(low[u],disc[v]);
			}
		}
		return x;
	}
	int Bridge(){
		int low[V],disc[V],parent[V];
		int vis[V];
		for (int i = 0; i < V; ++i)
		{
			vis[i] = 0;
			parent[i] = -1;
		}
		int x = 0;
		set<pii> bridge;
		for (int i = 0; i < V; ++i)
		{
			if(!vis[i])
				x+=DFS(i,0,low,disc,vis,parent,bridge,1);
		}
		vvi adj2 = adj;
		adj.clear();
		adj.resize(V,vi());
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < adj2[i].size(); ++j)
			{
				if(i<adj2[i][j] && !(present(bridge,mp(i,adj2[i][j]))))
					this->addEdge(i,adj2[i][j]);
			}
		}
		for (int i = 0; i < V; ++i)
		{
			vis[i] = 0;
			parent[i] = -1;
		}
		int c = 1;
		set<pii> temp;
		for (int i = 0; i < V; ++i)
		{
			if(!vis[i])
				DFS(i,0,low,disc,vis,parent,temp,c++);
		}
		c--;
		int deg[c];
		memset(deg,0,sizeof deg);
		// cout<<"hello"<<c<<endl;
		tr(bridge,it)
		{
			deg[ vis[it->ff] - 1 ]++;
			deg[ vis[it->ss] - 1 ]++;
		}
		int ans=0;
		for (int i = 0; i < c; ++i)
		{
			if(deg[i]==1){
				// cout<<"hi"<<i<<endl;
				ans++;
			}
		}
		return (ans+1)>>1;
	}
};


int main(){
	BOOST;
	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int v,e;
		cin>>v>>e;
		Graph G(v);
		for (int i = 0; i < e; ++i)
		{
			int a,b;
			cin>>a>>b;
			G.addEdge(a,b);
		}
		cout<<"Case "<<c++<<": "<<G.Bridge()<<endl;
	}
	return 0;
}