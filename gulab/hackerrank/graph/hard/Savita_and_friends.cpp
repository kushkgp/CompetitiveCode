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

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


ll dfs(int u, )


int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		pair<pii,int> kedge;
		vector<vpii> adj(n);
		for(int i = 0; i < m; i++){
			int u,v,c;
			cin>>u>>v>>c;
			if(i+1!=k){
				adj[--u].pb(mp(--v,c));
				adj[v].pb(mp(u,c));
			}
			else{
				kedge.ff.ff = --u;
				kedge.ff.ss = --v;
				kedge.ss = c;
			}
		}
		ll d1 = dfs(kedge.ff.ff,n,adj);
		ll d2 = dfs(kedge.ff.ss,n,adj);
		if(max(d1,d2)>=min(d1,d2)+kedge.ss){
			if(d1>d2){
				cout<<0<<d1;
			}
			else{
				cout<<kedge.ss<<d2;
			}
		}
		else{
			if(d1>d2){
				cout<<(d2+c-d1)/2<<(d1+d2+c)/2;
			}
			else{
				cout<<(d1+c-d2)/2<<(d1+d2+c)/2;
			}
		}
	}
}