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


int find_path(int s, int t, vvp &adj){
    // cout << s << " " << t << endl;
    deque<int> q;
    int n = adj.size();
    vi parent(n+1,-1);
    parent[s] = s;
    q.pb(s);
    bool path_found = false;
    int aug_flow = 0;
    while(!q.empty()){
        int where = q.front();
        // cout << where << " ";
        q.pop_front();
        for(int i=0;i<adj[where].size();i++){
            int next = adj[where][i].ff, wt = adj[where][i].ss;
            if(parent[next]==-1 && wt>0){
                q.pb(next);
                parent[next] = where;
                if(next == t){
                    path_found = true;
                    break;
                }
            }
        }
        if(path_found)
            break;
    }
    // cout << endl;
    if(parent[t]==-1)
        return 0;
    // cout << "cc" << endl;
    int max_flow = INT_MAX;
    int v = t;
    while(parent[v]!=v){
        int u = parent[v];
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i].ff == v){
                max_flow = min(max_flow, adj[u][i].ss);
                break;
            }
        }
        v = u;
    }
    v = t;
    while(parent[v]!=v){
        int u = parent[v];
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i].ff == v){
                adj[u][i].ss -= max_flow;
                break;
            }
        }
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i].ff == u){
                adj[v][i].ss += max_flow;
                break;
            }
        }
        v = u;
    }
    return max_flow;
}
int max_flow(int s, int t, vvp &adj){
    int result = 0;
    while(true){
        int crt = find_path(s,t,adj);
        if(crt==0)
            break;
        // cout << crt << endl;
        result += crt;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,T,m;
        cin >> n >> T >> m;
        vvp adj(2*n+2);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[2*a].pb(mp(2*b+1,1));
            adj[2*b+1].pb(mp(2*a,0));
            
            adj[2*b].pb(mp(2*a+1,1));
            adj[2*a+1].pb(mp(2*b,0));
        }
        for(int i=1;i<=n;i++){
            adj[0].pb(mp(2*i,T));
            adj[2*i].pb(mp(0,0));
            adj[2*i+1].pb(mp(1,1));
            adj[1].pb(mp(2*i+1,0));
        }
        cout << max_flow(0,1,adj) << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
