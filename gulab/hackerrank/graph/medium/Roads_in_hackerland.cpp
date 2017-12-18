/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
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

void prim(int n, vector<vpii> & adj, vector<vpii> & nadj){
	map<pii,int> m;
	vi dist(n,inf);
	vi vis(n,0);
	dist[0] = 0;
	m.insert(mp(mp(0,0),0));
	while(!m.empty()){
		pii x = m.begin()->ff;
		int u = x.ss, d = x.ff, parent = m[x];
		m.erase(m.begin());
		vis[u] = 1;
		if(u!=parent)
			nadj[parent].pb(mp(u,d));
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if(!vis[v] && dist[v]>w){
				if(m.find(mp(dist[v],v))!=m.end())
					m.erase(m.find(mp(dist[v],v)));
				dist[v] = w;
				m[mp(dist[v],v)]=u;
			}
		}
	}
}

int dfs(int u, int n, vector<vpii> & adj, vector<ll> & sol){
	int ans = 1;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i].ff, w = adj[u][i].ss;
		int x = dfs(v,n,adj,vis,sol);
		sol[w] = (ll)x*(n-x);
		ans+=x;
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vpii> adj(n);
	for(int i = 0; i < m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[--u].pb(mp(--v,c));
		adj[v].pb(mp(u,c));
	}
	vector<vpii> nadj(n);
	prim(n,adj,nadj);
	vector<ll> sol(m+1,0);
	dfs(0,n,nadj,sol);
	ll ans;
	string result;
	for(int i = 0; i < m; i++){
		ans = sol[i];
		result+=to_string(ans%2);
		sol[i+1]+=(ans>>1);
	}
	ans = sol[m];
	while(ans){
		result+=to_string(ans%2);
		ans>>=1;
	}
	reverse(all(result));
	cout<<result<<endl;
}