#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv= v<v<X>>;
typedef pair<int,int> pii;

int n, m, k;
v<pii> dir;
vv<int> a;
vv<int> d;

set<pair<int, pii> > s;

void dijstra(pii target){
	while(!s.empty()){
		pii u = s.begin()->ss;
		s.erase(s.begin());
		if(u == target)
			return;
		for(int i = 0; i < dir.size(); i++){
			pii v = mp(dir[i].ff+u.ff, dir[i].ss+u.ss);
			if(v.ff>=0 && v.ss>=0 && v.ff < n && v.ss < m && d[v.ff][v.ss] > a[v.ff][v.ss] + d[u.ff][u.ss]){
				s.erase(mp(d[v.ff][v.ss], v));
				s.insert(mp(d[v.ff][v.ss] = a[v.ff][v.ss] + d[u.ff][u.ss], v));
			}
		}		
	}
}

int main(){
	cin>>n>>m>>k;
	dir.pb(mp(0, -1));
	dir.pb(mp(-1, 0));
	dir.pb(mp(0, 1));
	dir.pb(mp(1, 0));
	a.resize(n, v<int>(m, 1e9));
	d.resize(n, v<int>(m, 1e9));
	deque<pii> q;
	pii target;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin>>c;
			if(c == '@'){
				d[i][j] = 0;
				s.insert(mp(0, mp(i, j)));
				a[i][j] = 0;
			}
			if(c == '.'){
				a[i][j] = 0;
			}
			if(c == 's'){
				a[i][j] = 1;
			}
			if(c == 'x'){
				target = mp(i, j);
				a[i][j] = 0;
			}
		}
	}
	dijstra(target);
	if(2*d[target.ff][target.ss] <= k)
		cout<<"SUCCESS"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}