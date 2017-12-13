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

int dfs(int u, vvi & adj, vi & vis){
	vis[u] = 1;
	int ans = 0;
	int odd_c = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			ans+=dfs(v,adj,vis);
			if(vis[v]==-1)
				odd_c=!odd_c;
			else
				ans++;
		}
	}
	if(!odd_c)
		vis[u]=-1;
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vvi adj(n);
	vi vis(n,0);
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}
	cout<<dfs(0,adj,vis)<<endl;
}