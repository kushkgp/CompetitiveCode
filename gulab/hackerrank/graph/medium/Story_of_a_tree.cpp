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

int dfs1(int u, int n, vvi & adj, set<pii> & s, vi & vis){
	vis[u] = 1;
	int ans = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			if(s.find(mp(u,v))!=s.end())
				ans++;
			ans+=dfs1(v,n,adj,s,vis);
		}
	}
	return ans;
}

int dfs2(int u, int n, int k, vvi & adj, set<pii> & s,int c, vi & vis){
	vis[u] = 1;
	int ans = 0;
	if(c>=k)
		ans++;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			if(s.find(mp(u,v))!=s.end())
				--c;
			if(s.find(mp(v,u))!=s.end())
				++c;
			ans+=dfs2(v,n,k,adj,s,c,vis);
			if(s.find(mp(u,v))!=s.end())
				++c;
			if(s.find(mp(v,u))!=s.end())
				--c;
		}
	}
	return ans;
}

int gcd(int a, int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		vvi adj(n);
		for(int i = 0; i < n-1; i++){
			int u,v;
			cin>>u>>v;
			adj[--u].pb(--v);
			adj[v].pb(u);
		}
		int g,k;
		cin>>g>>k;
		set<pii> s;
		for(int i = 0; i < g; i++){
			int u,v;
			cin>>u>>v;
			s.insert(mp(--u,--v));
		}
		vi vis(n,0);
		int curr = dfs1(0,n,adj,s,vis);
		fill(all(vis),0);
		int ans = dfs2(0,n,k,adj,s,curr,vis);
		int gc = gcd(n,ans);
		cout<<ans/gc<<"/"<<n/gc<<endl;
	}
}