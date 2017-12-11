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


int dfs(int n, int u, vvi & adj, vi & vis){
	vis[u] = 1;
	int ans = 1;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			ans+=dfs(n,v,adj,vis);
		}
	}
	return ans;
}

int main(){
	BOOST;
	int q;
	cin>>q;
	while(q--){
		int n,m,cl,cr;
		cin>>n>>m>>cl>>cr;
		vvi adj(n);
		for(int i=0; i < m; i++){
			int a,b;
			cin>>a>>b;
			adj[--a].pb(--b);
			adj[b].pb(a);
		}
		vi vis(n,0);
		ll ans=0;
		for(int i = 0 ; i<n; i++){
			if(!vis[i]){
				int x = dfs(n,i,adj,vis);
				if(cl>cr){
					ans+= cl;
					ans+= (ll)(x-1)*cr;
				}
				else{
					ans+= (ll)x*cl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}