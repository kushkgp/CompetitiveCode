/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
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

void clean_str(string& inp){
	F1(i,0,inp.size()-1){
		if(inp[i]=='+' || inp[i]=='='){
			inp[i]=' ';
		}
	}
}

void bfs(int st, vvpii &adj, vvi &value, vvi &visited, vi &root){
	int n = adj.size();
	queue<pair<pii, int> >	myq;
	F1(i,0,(int)adj[st].size()-1){
		pii crt = adj[st][i];
		myq.push(mp(mp(crt.ff, 0), crt.ss));
		visited[crt.ff][0]=1;
	}
	// cout << "Starting"
	while(!myq.empty()){
		pair<pii, int> crt = myq.front();
		myq.pop();
		pii crt_nd = crt.ff;
		int crt_val = crt.ss;
		value[crt_nd.ff][crt_nd.ss] = crt_val;
		root[crt_nd.ff] = st;
		F1(i,0,(int)adj[crt_nd.ff].size()-1){
			pii dst_nd = adj[crt_nd.ff][i];
			if(!visited[dst_nd.ff][!crt_nd.ss]){
				visited[dst_nd.ff][!crt_nd.ss] = 1;
				int new_val;
				if(!crt_nd.ss){
					new_val = crt_val - dst_nd.ss;
				}
				else{
					new_val = crt_val + dst_nd.ss;
				}
				myq.push(mp(mp(dst_nd.ff, !crt_nd.ss), new_val));
			}
		}
	}
}

void bfs_util(vvpii &adj, vvi &value, vvi &visited, vi &root){
	F1(i,0,(int)adj.size()-1){
		if(!(visited[i][0] || visited[i][1])){
			visited[i][1] = 1;
			value[i][1] = 0;
			root[i] = i;
			bfs(i,adj,value, visited, root);
		}
	}
}

pii get_ans(int a ,int b, vvi &value, vvi &visited, vi &root){
	if(root[a] == root[b]){
		if(visited[a][0] && visited[b][1]){
			return mp(1, value[a][0] - value[b][1]);
		}
		if(visited[a][1] && visited[b][0]){
			return mp(1, value[b][0] - value[a][1]);
		}
	}
	return mp(0,-1);
}

int main(){
	int t,C=1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<string, int> ids;
		vector<string> names;
		vvpii adj;
		F1(i,0,n-1){
			string inp;
			cin >> inp;
			clean_str(inp);
			stringstream ss(inp);
			string a,b;
			int k;
			ss >> a >> b >> k;
			if(ids.find(a)==ids.end()){
				ids[a] = names.size();
				names.pb(a);
				adj.pb(vpii());
			}
			if(ids.find(b)==ids.end()){
				ids[b] = names.size();
				names.pb(b);
				adj.pb(vpii());
			}
			adj[ids[a]].pb(mp(ids[b],k));
			adj[ids[b]].pb(mp(ids[a],k));
		}
		int q;
		cin >> q;

		vvi visited(adj.size() , vi(2,0));
		vvi value(adj.size() , vi(2,0));
		vi root(adj.size(),-1);

		// cout << "Builting graph" << endl;

		bfs_util(adj, value, visited, root);


		// cout << "Built graph" << endl;
		// F1()
		cout << "Case #"<< C++ << ":"<< endl;
		F1(i,0,q-1){
			string inp;
			cin >> inp;
			clean_str(inp);
			stringstream ss(inp);
			string a, b;
			ss >> a >> b;
			pii ans = mp(0,-1);
			if(ids.find(a) != ids.end() && ids.find(b) != ids.end())
				ans = get_ans(ids[a],ids[b],value, visited, root);
			if(ans.ff)
				cout << a << "+"<< b << "=" << ans.ss << endl;
		}
	}
}