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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

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

void bfs(int s, int n, vvi & adj, vi & vis){
	queue<int> q;
	q.push(s);
	vis[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(vis[v]==-1){
				q.push(v);
				vis[v] = vis[u]+1;
			}
		}
	}
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		vvi adj(n);
		for(int i = 0; i<m; i++){
			int u,v;
			cin>>u>>v;
			adj[--u].pb(--v);
			adj[v].pb(u);
		}
		int start;
		cin>>start;
		start--;
		vi vis(n,-1);
		bfs(start,n,adj,vis);
		for(int i = 0; i<n; i++){
			if(i!=start){
				cout<<(vis[i]>0?6:1)*vis[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}