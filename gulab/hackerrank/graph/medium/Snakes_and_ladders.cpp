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

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

void bfs(int start, vvi & adj, vi & vis){
	vis[start] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(vis[v]==-1){
				vis[v] = vis[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		vvi adj(100);
		map<int,int> m;
		for(int j = 0; j<2; j++){
			int n;
			cin>>n;
			for(int i = 0; i < n; i++){
				int u,v;
				cin>>u>>v;
				m.insert(mp(--u,--v));
			}
		}
		for(int i = 0; i < 99; i++){
			for(int j = 1; j <= 6 && i+j<100; j++){
				if(m.find(i+j)!=m.end())
					adj[i].pb(m.find(i+j)->ss);
				else
					adj[i].pb(i+j);
			}
		}
		vi vis(100, -1);
		bfs(0,adj,vis);
		cout<<vis[99]<<endl;
	}
}