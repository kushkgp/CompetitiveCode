#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define ff first
#define ss second

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main() {
    int n,m;
    cin >> n >> m;
    
    vvpii adj(n+1);
    FOR(i,m){
        int x,y,r;
        cin >> x >> y >> r;
        adj[x].pb(mp(y,r));
        adj[y].pb(mp(x,r));
    }
    int s;
    cin >> s;

    vi dist(n+1,inf);
    vi comp(n+1,0);
    dist[s]=0;
    set<pair<int,int> > hp; 
    hp.insert(mp(0,s));
    int ans = 0;
    while(!hp.empty()){
        pii crt = *hp.begin();
        hp.erase(hp.begin());
        int crt_node = crt.ss;
        comp[crt_node] = 1;
        //cout << crt_node << " " << crt.ff << " " ;
        ans += crt.ff;
        for(int i=0;i<adj[crt_node].size();i++){
            pii x = adj[crt_node][i];
            if(dist[x.ff] > x.ss && !comp[x.ff]){
                hp.erase(mp(dist[x.ff],x.ff));
                dist[x.ff] = x.ss;
                hp.insert(mp(dist[x.ff],x.ff));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
