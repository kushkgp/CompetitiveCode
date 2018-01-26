#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;


int dfs_prune(vvp &adj, vvp &adj_p, vi &to_vis, int crt, vi &vis){
    int mst = 0;
    // cout << "\ndfs at " << crt << "--------" << endl;
    vis[crt] = 1;
    //if(to_vis[crt]==1)
    //    keep = 1;
    for(int i=0;i<adj[crt].size();i++){
        pii to = adj[crt][i];
        // cout << crt << "-" << to.ff << " " << to.ss<< endl;
        if(!vis[to.ff]){
            if(to_vis[to.ff]==1){
                adj_p[crt].pb(mp(to.ff, to.ss));
                adj_p[to.ff].pb(mp(crt, to.ss));
                mst += to.ss;
            }
            // cout << " mst = " << mst << " ";
            int a;
            if(a = dfs_prune(adj,adj_p,to_vis,to.ff,vis)){
                mst += a;
                // cout << crt << " " << to.ff << endl;
                if(!to_vis[to.ff]){
                    adj_p[crt].pb(mp(to.ff, to.ss));
                    adj_p[to.ff].pb(mp(crt, to.ss));
                    mst+=to.ss;
                }
            }
        }
    }
    // cout << "finished dfs at " << crt << "with "<< mst << "-======" << endl;
    return mst;
}

pii dfs_farthest(vvp &adj, int crt, vi &vis){
    // cout << "\ndfs at " << crt << "--------" << endl;
    vis[crt] = 1;
    pii ans = mp(crt,0);
    for(int i=0;i<adj[crt].size();i++){
        pii to = adj[crt][i];
        if(!vis[to.ff]){
            pii child = dfs_farthest(adj, to.ff, vis);
            if(child.ss + to.ss > ans.ss){
                ans = child;
                ans.ss += to.ss;
                // cout << "Updated to " << ans.ff << " " << ans.ss << endl;
            }
        }
    }
    // cout << "finished dfs at " << crt << " with distance=== " << ans.ff << " " << ans.ss << endl; 
    return ans;
}

int main() {
    int n,k;
    cin >> n >> k;
    vi to_vis(n,0);
    vvp adj(n);
    int x;
    FOR(i,k){
        int a;
        cin >> a;
        a--;
        to_vis[a] = 1;
        x = a;
    }
    FOR(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    // cout << x << " ";
    vi vis(n,0);
    vvp adj_p(n);
    int mst = dfs_prune(adj,adj_p,to_vis, x, vis);
    fill(all(vis),0);
    // cout << x << " has longest dist to ";
    pii y = dfs_farthest(adj_p, x, vis);
    // cout << y.ff << " which is " << y.ss << endl;
    fill(all(vis),0);
    y = dfs_farthest(adj_p, y.ff, vis);
    // cout << mst << " " << y.ss << " ";
    cout << 2*mst - y.ss << endl;
    return 0;
}
