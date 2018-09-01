#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef pair<int,int> pii;
typedef long long ll;

int m, n;
v<pii> dir;


void dijkstra(pii src, vv<int> & a, vv<int> & d){
	set<pair<int, pii> > s;
	d[src.ff][src.ss] = 0;
	s.insert(mp(0, src));

	while(!s.empty()){
		pii u = s.begin()->ss;
		s.erase(s.begin());
		for(int i = 0; i < dir.size(); i++){
			pii v = mp(u.ff+dir[i].ff, u.ss+dir[i].ss);
			if(v.ff>=0 && v.ff < m && v.ss >=0 && v.ss < n){
				int w = INT_MAX;
				if(a[u.ff][u.ss] == 10 || a[v.ff][v.ss] == 10)
					w = 2;
				else if(abs(a[u.ff][u.ss] - a[v.ff][v.ss]) == 1)
					w = 3;
				else if(a[u.ff][u.ss] == a[v.ff][v.ss])
					w = 1;
				if(w!=INT_MAX){
					if(d[v.ff][v.ss] > d[u.ff][u.ss] + w){
						s.erase(mp(d[v.ff][v.ss], v));
						s.insert(mp(d[v.ff][v.ss] = d[u.ff][u.ss] + w, v));
					}
				}
			}
		}
	}
}


int main(){
	dir.pb(mp(1, 0));
	dir.pb(mp(-1, 0));
	dir.pb(mp(0, 1));
	dir.pb(mp(0, -1));
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		vv<int> a(m, v<int>(n));
		vv<int> d(m, v<int>(n, INT_MAX));
		pii src;
		int f1=0, f2 = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				char c;
				cin>>c;
				if(c == 'X' || c == '$')
					a[i][j] = 10;
				else
					a[i][j] = c - '0';
				if(c == 'X'){
					f1 = 1;
					src = mp(i, j);
				}
				if(c == '$')
					f2 = 1;
			}
		}
		if(!f1 || !f2){
			cout<<0<<endl;
			continue;
		}
		dijkstra(src, a, d);

		v<int> w;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] == 10 && src!=mp(i, j)){
					w.pb(d[i][j]);
				}
			}
		}
		sort(w.begin(), w.end());
		int m = INT_MIN;
		for(int i = 0; i < w.size(); i++){
			m = max(m, w[i]);
		}

		if(m == INT_MAX)
			cout<<"-1"<<endl;
		else{
			m = INT_MAX;
			for(int i = 0; i < (1<<w.size()); i++){
				int f0 = 0, f1 = 0, sum0 = 0, sum1 = 0;
				for(int j = w.size()-1; j >= 0; j--){
					if((1<<j)&i){
						sum1+=w[j];
						if(f1)
							sum1+=w[j];
						else
							f1 = 1;
					}
					else{
						sum0+=w[j];
						if(f0)
							sum0+=w[j];
						else
							f0 = 1;
					}
				}
				m = min(m, max(sum1, sum0));
			}
			cout<<m<<endl;
		}
	}
}