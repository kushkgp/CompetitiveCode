#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv= v<v<X>>;
typedef pair<int,int> pii;
int main(){
	int n, m, k;
	cin>>n>>m>>k;
	vv<int> a(n, v<int>(m, -1));
	vv<int> d(n, v<int>(m, -1));
	vv<int> dis(n, v<int>(m, 0));
	deque<pii> q;
	pii target;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin>>c;
			if(c == '@'){
				d[i][j] = 0;
				q.push_back(mp(i, j));
				a[i][j] = 0;
				dis[i][j] = 1;
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
	v<pii> dir;
	dir.pb(mp(0, -1));
	dir.pb(mp(-1, 0));
	dir.pb(mp(0, 1));
	dir.pb(mp(1, 0));
	// cout<<"hi"<<endl;
	while(!q.empty()){
		pii u = q.front();
		q.pop_front();
		// cout<<u.ff<<" "<<u.ss<<endl;
		for(int i = 0; i < dir.size(); i++){
			pii v = mp(u.ff+dir[i].ff, u.ss+dir[i].ss);
			if(v.ff>=0 && v.ff<n && v.ss>=0 && v.ss<m && a[v.ff][v.ss]>=0){
				if(!dis[v.ff][v.ss] && a[v.ff][v.ss]>-1){
					if(a[v.ff][v.ss])
						q.push_back(mp(v.ff, v.ss));
					else
						q.push_front(mp(v.ff, v.ss));
					dis[v.ff][v.ss] = 1;
					d[v.ff][v.ss] = d[u.ff][u.ss] + a[v.ff][v.ss];
				}
			}
		}
	}
	// cout<<target.ff<<" "<<target.ss<<" "<<d[target.ff][target.ss]<<endl;
	if(d[target.ff][target.ss]!=-1 && 2*d[target.ff][target.ss] <= k)
		cout<<"SUCCESS"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}