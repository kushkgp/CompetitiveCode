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

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        
        cin >> n >> m;
        vi dist(n+1,inf);
        vvp adj(n+1);
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            adj[x].pb(mp(y,r));
            adj[y].pb(mp(x,r));
        }
        int s;
        cin >> s;
        
        dist[s] = 0;
        set<pr> hp;
        hp.insert(mp(0,s));
        while(!hp.empty()){
            pr crt = *hp.begin();
            hp.erase(hp.begin());
            int v = crt.ss, d = crt.ff;
            for(int i=0;i<adj[v].size();i++){
                int to = adj[v][i].ff, cost = adj[v][i].ss;
                if(d+cost<dist[to]){
                    if(hp.find(mp(dist[to],to))!=hp.end())
                        hp.erase(mp(dist[to],to));
                    dist[to] = d + cost;
                    hp.insert(mp(dist[to],to));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(i==s)
                continue;
            if(dist[i]==inf)
                cout << -1 << " ";
            else
                cout<< dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
