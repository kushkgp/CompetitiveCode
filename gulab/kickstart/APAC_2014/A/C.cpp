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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		map<string,int> m;
		vector<vpii> adj;
		int f = 0;
		F1(i,0,n-1){
			cin>>s;
			string x,y;
			int z;
			F1(j,0,s.length()-1)
				if(s[j]=='+' || s[j]=='=')
					s[j]=' ';
			istringstream is(s);
			is>>x>>y>>z;
			if(m.find(x)==m.end()){
				m[x] = f++;
				adj.pb(vpii());
			}
			if(m.find(y)==m.end()){
				m[y] = f++;
				adj.pb(vpii());
			}
			adj[m[x]].pb(mp(m[y],z));
			if(x!=y)
				adj[m[y]].pb(mp(m[x],z));
		}
		int q;
		cin>>q;
		printf("Case #%d:\n", cnt++);
		while(q--){
			cin>>s;
			F1(j,0,s.length()-1)
				if(s[j]=='+')
					s[j]=' ';
			string x,y;
			istringstream is(s);
			is>>x>>y;
			if(m.find(x)!=m.end() && m.find(y)!=m.end()){
				vi vis(f,0);
				queue<pii> Q;
				int p = m[x], q = m[y];
				F1(i,0,adj[p].size()-1){
					int v = adj[p][i].ff;
					int w = adj[p][i].ss;
					vis[v]=1;
					Q.push(mp(v,w));
				}
				// cout<<x<<y<<endl;
				while(!Q.empty()){
					pii pa = Q.front();
					Q.pop();
					int u = pa.ff;
					int w = pa.ss;
					// if(x==string("a"))
					// 	cout<<"hi"<<u<<endl;
					if(u==m[y]){
						cout<<x<<"+"<<y<<"="<<w<<endl;
						break;
					}
					F1(i,0,adj[u].size()-1){
						int v1 = adj[u][i].ff;
						F1(j,0,adj[v1].size()-1){
							int v = adj[v1][j].ff;
							if(!vis[v]){
								vis[v]=1;
								Q.push(mp(v,w-adj[u][i].ss+adj[v1][j].ss));
							}
						}
					}
				}
			}
		}
	}
}