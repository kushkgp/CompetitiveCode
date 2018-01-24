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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t,C=1;
	cin >> t;
	while(t--){
		cout << "Case #" << C++ << ":";
		int n,m,k;
		cin >> n >> m >> k;
		vector<vvpii> adj(24,vvpii(n,vpii()));
		F1(i,0,m-1){
			int x,y;
			cin >> x >> y;
			x--;y--;
			F1(t,0,23){
				int cost;
				cin >> cost;
				adj[t][x].pb(mp(y,cost));
				adj[t][y].pb(mp(x,cost));
			}
		}
		F1(i,0,k-1){
			int d,s;
			cin >> d >> s;
			d--;
			vi time(n,inf);
			set<pii > hp;
			time[0] = 0;
			hp.insert(mp(0,0));
			while(!hp.empty()){
				int src = (*hp.begin()).ss;
				hp.erase(hp.begin());
				int crt_time = (time[src] + s)%24;
				vpii &sadj = adj[crt_time][src]; 
				for(int i=0;i<sadj.size();i++){
					pii crt = sadj[i];
					if(time[crt.ff] > time[src] + crt.ss){
						hp.erase(mp(time[crt.ff],crt.ff));
						time[crt.ff] = time[src] + crt.ss;
						hp.insert(mp(time[crt.ff],crt.ff));
					}
				}
			}
			cout << " " << (time[d] < inf ? time[d]:-1);
		}
		cout << endl;
	}
}