/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t,C=1;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;

		vvi adj(n,vi(n,inf));
		vvi path(n,vi(n,inf));
		vector<pair< pii,int> >edge(m);

		F1(i,0,m-1){
			int u,v,c;
			cin >> u >> v >> c;
			adj[u][v] = adj[v][u] = min(c,adj[u][v]);
			path[u][v] = path[v][u] =  adj[u][v];
			edge[i] = mp(mp(u,v),c);
		}
		F1(i,0,n-1)
			path[i][i] = 0;
		F1(k,0,n-1){
			// path[k][k]= 0;
			F1(i,0,n-1){
				F1(j,0,n-1){
					path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
					// path[j][i] = min(path[j][i], path[j][k]+path[k][i]);
				}
			}
		}
		cout << "Case #" << C++ << ":" << endl;
		F1(i,0,m-1){
			pii e = edge[i].ff;
			if(path[e.ff][e.ss]!=adj[e.ff][e.ss] || adj[e.ff][e.ss] < edge[i].ss)
				cout << i << endl;
		}
		// if(C==2)
		// 	cout << path[6][74] << " " << adj[6][74] << endl;
	}
}