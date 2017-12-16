#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;


int main() {
    int n,m;
    cin >> n >> m;
    vvp adj(n);
    for(int i=0;i<m;i++){
       int a,b,c;
       cin >> a >> b >> c;
        --a;--b;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    vi dist(n, INT_MAX);
    dist[0] = 0;
    set<pii> dk;
    dk.insert(mp(0,0));
    while(!dk.empty()){
        pii crt = *dk.begin();
        dk.erase(dk.begin());
        for(int i=0;i<adj[crt.ss].size();i++){
            pii to = adj[crt.ss][i];
            if(dist[to.ff] > max(crt.ff, to.ss)){
                dk.erase(mp(dist[to.ff], to.ff));
                dist[to.ff] = max(crt.ff, to.ss);
                dk.insert(mp(dist[to.ff], to.ff));
            }
        }
    }
    if(dist[n-1]==INT_MAX)
        cout << "NO PATH EXISTS" << endl;
    else
        cout << dist[n-1] << endl;
    return 0;
}
