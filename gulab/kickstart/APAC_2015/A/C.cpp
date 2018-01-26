/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void ans(vector<vpii> & adj, int n, vpii & edges){
	F1(i,0,n-1){
		vi d(n,inf);
		vvi h(n,vi());
		set<pii> s;
		d[i] = 0;
		s.insert(mp(0,i));
		while(!s.empty()){
			int u = s.begin()->ss;
			int w = s.begin()->ff;
			s.erase(s.begin());
			F1(j,0,(int)adj[u].size()-1){
				int v = adj[u][j].ff;
				int index = adj[u][j].ss;
				if(d[v] > d[u]+edges[index].ff){
					h[v].clear();
					h[v].pb(index);
					s.erase(mp(d[v],v));
					d[v] = d[u]+edges[index].ff;
					s.insert(mp(d[v],v));
				}
				else if(d[v] == d[u]+edges[index].ff)
					h[v].pb(index);
			}
		}
		F1(j,0,n-1)
			F1(k,0,(int)h[j].size()-1){
				// cout<<h[j][k]<<endl;
				edges[h[j][k]].ss = 1;
			}
	}
	F1(i,0,(int)edges.size()-1)
		if(!edges[i].ss)
			cout<<i<<endl;
}


int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vpii> adj(n,vpii());
		vpii edges(m);
		F1(i,0,m-1){
			int a,b,c;
			cin>>a>>b>>c;
			edges[i] = mp(c,0);
			adj[a].pb(mp(b,i));
			adj[b].pb(mp(a,i));
		}
		printf("Case #%d:\n", cnt++);
		ans(adj,n,edges);
	}
}