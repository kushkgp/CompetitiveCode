/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

int find(int x, vi & set){
	if(set[x]!=x){
		set[x] = find(set[x],set);
	}
	return set[x];
}

void union_s(int x, int y, vi & set){
	int i = find(x,set);
	int j = find(y,set);
	if(i!=j)
		set[i] = j;
}

int main(){
	int n,m;
	cin>>n>>m;
	vi set(n);
	vector<pair<pii,pii> > edges(m);
	for(int i = 0; i < n; i++)
		set[i] = i;
	for(int i = 0; i < m; i++){
		int x,y,w;
		cin>>x>>y>>w;
		--x,--y;
		edges[i] = mp(mp(w,w+x+y),mp(x,y));
	}
	asort(edges);
	int ans=0;
	for(int i = 0; i < m; i++){
		int x = edges[i].ss.ff, y = edges[i].ss.ss;
		if(find(x,set)!=find(y,set)){
			union_s(x,y,set);
			ans+=edges[i].ff.ff;
		}
	}
	cout<<ans<<endl;
}