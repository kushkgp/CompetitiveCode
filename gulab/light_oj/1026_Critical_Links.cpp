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
	int DFS(int u, int time, int low[], int disc[], bool vis[],int parent[],vpii & bridge){
		disc[u] = low[u] = time++;
		vis[u] = true;
		int x = 0;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if(!vis[v]){
				parent[v] = u;
				x+=DFS(v,time,low,disc,vis,parent,bridge);
				low[u] = min(low[u],low[v]);
				if (low[v] > disc[u]){
					bridge.pb(mp(min(u,v),max(u,v)));
					x++;
				}
			}
			else if(parent[u]!=v){
				low[u] = min(low[u],disc[v]);
			}
		}
		return x;
	}
	void Bridge(){
		int low[V],disc[V],parent[V];
		bool vis[V],ap[V];
		for (int i = 0; i < V; ++i)
		{
			vis[i] = 0;
			parent[i] = -1;
			ap[i]=false;
		}
		int x = 0;
		vpii bridge;
		for (int i = 0; i < V; ++i)
		{
			if(!vis[i])
				x+=DFS(i,0,low,disc,vis,parent,bridge);
		}
		sort(all(bridge));
		cout<<x<<" critical links\n";
		tr(bridge,it){
			cout<<it->ff<<" - "<<it->ss<<endl;
		}
	}
};


int main(){
	BOOST;
	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int v;
		cin>>v;
		Graph G(v);
		for (int i = 0; i < v; ++i)
		{
			int a,b;
			string s;
			cin>>a>>s;
			sscanf(s.c_str(),"(%d)",&b);
			for (int j = 0; j < b; ++j)
			{
				int x;
				cin>>x;
				G.addEdge(a,x);
			}
		}
		cout<<"Case "<<c++<<":\n";
		G.Bridge();
	}
	return 0;
}