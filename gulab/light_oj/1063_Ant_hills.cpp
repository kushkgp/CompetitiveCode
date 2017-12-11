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
	int DFS(int u, int time, int low[], int disc[], bool vis[],int parent[],bool ap[]){
		disc[u] = low[u] = time++;
		vis[u] = true;
		int child = 0;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if(!vis[v]){
				child++;
				parent[v] = u;
				DFS(v,time,low,disc,vis,parent,ap);
				low[u] = min(low[u],low[v]);
				if (parent[u] == -1 && child > 1)
					ap[u] = true;
				if (parent[u] != -1 && low[v] >= disc[u])
					ap[u] = true;
			}
			else if(parent[u]!=v){
				low[u] = min(low[u],disc[v]);
			}
		}
		return child;
	}
	int AP(){
		int low[V],disc[V],parent[V];
		bool vis[V],ap[V];
		for (int i = 0; i < V; ++i)
		{
			vis[i] = 0;
			parent[i] = -1;
			ap[i]=false;
		}
		int x = DFS(0,0,low,disc,vis,parent,ap);
		int result=0;
		for (int i = 0; i < V; ++i)
		{
			if(ap[i])
				result++;
		}
		return result;
	}
};


int main(){
	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int v, e;
		cin>>v>>e;
		Graph G(v);
		for (int i = 0; i < e; ++i)
		{
			int a,b;
			cin>>a>>b;
			G.addEdge(a-1,b-1);
		}
		cout<<"Case "<<c++<<": "<<G.AP()<<endl;
	}
	return 0;
}