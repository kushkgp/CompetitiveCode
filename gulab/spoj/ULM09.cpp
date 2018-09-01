#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MAX 200005
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
pair<int, pii> adj[MAX];
int s[MAX];

int find(int x){
	while(x !=  s[x]){
		s[x] = s[s[x]];
		x = s[x];
	}
	return x;
}

void union_s(int x, int y){
	s[find(x)] = find(y);
}

int main(){
	cin>>m>>n;
	while(m && n){
		for(int i = 0; i < m; i++)
			s[i] = i;

		ll sum = 0;
		for(int i = 0; i < n; i++){
			int x, y, w;
			cin>>x>>y>>w;
			adj[i] = mp(w, mp(x, y));
			sum+=w;
		}
		sort(adj, adj + n);

		ll ans = 0;
		for(int i = 0; i < n; i++){
			int w = adj[i].ff;
			int u = adj[i].ss.ff;
			int v = adj[i].ss.ss;
			if(find(u) != find(v)){
				union_s(u, v);
				ans+=w;
			}
		}
		// cout<<sum<<" "<<ans<<endl;
		cout<<sum - ans<<endl;
		cin>>m>>n;
	}
	return 0;
}