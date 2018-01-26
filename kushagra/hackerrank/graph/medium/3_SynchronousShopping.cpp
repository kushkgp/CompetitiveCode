#include <bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pr>
#define vvp vector<vp>

#define ff first
#define nd pair<int,int>
#define ss second
#define mp make_pair
#define pb push_back
#define inf 2E9

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vi mask(n+1,0);
    vvi dist(n+1,vi(1024,inf));
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int x;
            cin >> x;
            x--;
            mask[i] |= (1<<x);
        }
    }
    vvp adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    
    set<pair<int,nd> > dijk;
    dijk.insert(mp(0,mp(1,mask[1])));
    dist[1][mask[1]]=0;
    int ans = inf;
    while(!dijk.empty()){
        pair<int,nd> crt = *dijk.begin();
        dijk.erase(dijk.begin());
        int v = crt.ss.ff, d = crt.ff, m = crt.ss.ss;
        for(int i=0;i<adj[v].size();i++){
            int to = adj[v][i].ff;
            int new_mask = m | mask[to];
            int cost = adj[v][i].ss;
            // cout <<"----->"<< d+cost << " " << dist[to][new_mask] << endl;
            if(d+cost < dist[to][new_mask]){
                dijk.erase(mp(dist[to][new_mask],mp(to,new_mask)));
                dist[to][new_mask] = dist[v][m] + cost;
                // dist[to][new_mask] = d + cost;
                dijk.insert(mp(dist[to][new_mask],mp(to,new_mask)));
                // cout << dist[to][new_mask] << " " << to << " " << new_mask << endl;
            }
        }
        //cout << k << endl;
    }
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            //cout << i << " " << j << " " << endl;
            if((j|i) == ( (1<<k) - 1 ) )
                ans = min(ans, max(dist[n][i], dist[n][j]));
        }    
    }
    cout << ans << endl;
    
    
    return 0;
}
