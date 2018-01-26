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
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		int start;
		cin>>n>>m;
		set<pii> s;
		for(int i = 0; i < m; i++){
			int u,v;
			cin>>u>>v;
			s.insert(mp(--u,--v));
		}
		cin>>start;
		--start;

		vi dist(n,-1);
		queue<int> q;
		set<int> notdisc;
		for(int i = 0; i < n; i++)
			notdisc.insert(i);
		dist[start] = 0;
		notdisc.erase(notdisc.find(start));
		q.push(start);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto & v : notdisc){
				if(s.find(mp(u,v))==s.end() && s.find(mp(v,u))==s.end()){
					q.push(v);
					dist[v] = dist[u]+1;
					notdisc.erase(notdisc.find(v));
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(i!=start)
				cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
}