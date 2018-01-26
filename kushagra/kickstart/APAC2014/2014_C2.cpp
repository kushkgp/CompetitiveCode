/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
#define mod 1000000007

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
typedef vector<vpii> vvpii;

int main(){
	// cout << inf << endl;
	int t;
	cin >> t;
	int C=1;
	while(t--){
		cout << "Case #" << C++ << ":" <<endl;
		int n;
		cin >> n;
		int cnt;
		vvpii adj(400000, vpii());

		for(int ln=0;ln<n;ln++){
			int stn, wt;
			cin >> cnt >> wt;
			for(int stn=1;stn<cnt;stn++){
				int time;
				cin >> time;
				adj[ln*2001+stn].push_back(make_pair(ln*2001+stn-1,time));
				adj[ln*2001+stn-1].push_back(make_pair(ln*2001+stn,time));
			}
			for(int i=0;i<cnt;i++){
				adj[ln*2001+i+1000].push_back(make_pair(ln*2001+i,wt));
				adj[ln*2001+i].push_back(make_pair(ln*2001+i+1000,0));
			}
		}
		int m;
		cin >> m;
		for(int i=0;i<m;i++){
			int ln1,stn1,ln2,stn2,time;
			cin >> ln1 >> stn1 >> ln2 >> stn2 >> time;
			ln1--;stn1--;ln2--;stn2--;
			adj[ln1*2001+stn1+1000].push_back(make_pair(ln2*2001+stn2+1000,time));
			adj[ln2*2001+stn2+1000].push_back(make_pair(ln1*2001+stn1+1000,time));
		}
		int q;
		cin >> q;
		while(q--){
			set<pair<int,int> > hp;
			int l1,s1,l2,s2;
			vi dist(300000,inf);
			cin >> l1 >> s1 >> l2 >> s2;
			l1--;s1--;l2--;s2--;
			dist[l1*2001+s1+1000] = 0;
			hp.insert(mp(0,l1*2001+s1+1000));
			while(!hp.empty()){
				pii node = *hp.begin();
				hp.erase(hp.begin());
				int src = node.ss;
				for(int i=0;i<adj[src].size();i++){
					pii dest = adj[src][i];
					if(dist[dest.ff] > dist[src] + dest.ss){
						hp.erase(mp(dist[dest.ff],dest.ff));
						dist[dest.ff] = dist[src] + dest.ss;
						hp.insert(mp(dist[dest.ff],dest.ff));
					}
				}
			} 
			int ans = min(dist[l2*2001+s2],dist[l2*2001+s2+1000]);
			cout <<  (ans==inf?-1:ans) << endl;
		}
	}
}