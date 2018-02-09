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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

map<string, int> m;

bool dfs(int u, vi & vis, vi & know, vvi & adj){
	vis[u] = 1;
	know[u] = 0;
	int f = adj[u].size()?1:0;
	F1(i,0,(int)adj[u].size()-1){
		int v = adj[u][i];
		if(!vis[v])
			f&=dfs(v,vis,know,adj);
		else
			f&=know[v];
		if(!f)
			break;
	}
	return know[u]=f;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		int node = 0;
		vvi adj;
		vi vis,know;
		m.clear();
		getline(cin,s); 
		F1(i,0,n-1){
			getline(cin,s);
			s = s.substr(0,s.length()-1);
			int j = 0;
			for(; j<(int)s.length(); j++){
				if(s[j]=='=' || s[j]=='(' || s[j]==',')
					s[j] = ' ';
			}
			stringstream ss(s);
			int f = 0, u, v;
			while(getline(ss, s, ' ')){
				if(s!="" && f!=1){
					if(m.find(s)==m.end()){
						m[s] = node++;
						know.pb(0);
						vis.pb(0);
						adj.pb(vi());
					}
					if(f){
						v = m[s];
						adj[u].pb(v);
					}
					else
						u = m[s];
				}
				if(s!="")
					f++;
				else
					break;
			}
			if(f==2)
				know[u] = vis[u] = 1;
		}
		int f = 1;
		F1(i,0,node-1){
			if(!vis[i])
				f&=dfs(i,vis,know,adj);
			else
				f&=know[i];
			if(!f)
				break;
		}
		printf("Case #%d: %s\n", cnt++, f?"GOOD":"BAD");
	}
}