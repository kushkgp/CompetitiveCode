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

int dfs(int u, vi & vis, vvi & adj, int f){
	vis[u] = f+1;
	int ret = 1;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			ret=dfs(v,vis,adj,!f);
			if(!ret)
				break;
		}
		else if((vis[v]-1)==f){
			ret=0;
			break;
		}
	}
	return ret;
}

int main(){
	int t,cnt=1;
	cin>>t;
	while(t--){
		int n,tot=0;
		cin>>n;
		vvi adj;
		map<string,int> m;
		for(int i = 0; i < n; i++){
			string a,b;
			cin>>a>>b;
			if(m.find(a)==m.end()){
				m[a]=tot++;
				adj.pb(vi());
			}
			if(m.find(b)==m.end()){
				m[b]=tot++;
				adj.pb(vi());
			}
			adj[m[a]].pb(m[b]);
			adj[m[b]].pb(m[a]);
		}
		int f = 1;
		vi vis(tot,0);
		for(int i = 0; i < tot; i++){
			if(!vis[i]){
				f=dfs(i,vis,adj,0);
				if(!f)
					break;
			}
		}
		printf("Case #%d: ", cnt++);
		if(f)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
}