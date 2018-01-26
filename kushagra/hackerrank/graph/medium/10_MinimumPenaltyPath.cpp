#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define vvp vector<vp>
#define el vector<pair<int,pii > >
#define mp make_pair
#define pb push_back
#define ss second
#define ff first

int main() {
    //BFS
    int n,m;
    cin >> n >> m ;
    
    vvp adj(n+1);
    for(int i=0;i<m;i++){
        int x,y,c;
        cin >> x >> y >> c;
        adj[x].pb(mp(y,c));
        adj[y].pb(mp(x,c));
    }
    
    int s,d;
    cin >> s >> d;
    
    bool visited[1001][1024];
    for(int i=0;i<1001;i++){
        for(int j=0;j<1024;j++){
            visited[i][j]=0;
        }
    }
    
    queue <pair<int, int> > q;
    
    q.push(mp(s,0));
    
    visited[s][0]=1;
    
    while(!q.empty()){
        pii crt = q.front();
        q.pop();
        int crt_nd = crt.ff;
        int crt_d = crt.ss;
        for(int i=0;i<adj[crt_nd].size();i++){
            pii to_nd = adj[crt_nd][i];
            if(!visited[to_nd.ff][crt_d|to_nd.ss]){
                visited[to_nd.ff][crt_d|to_nd.ss] = 1;
                q.push(mp(to_nd.ff,crt_d|to_nd.ss));
            }
        }
    }
    int i;
    for(i=0;i<(1<<10);i++){
        if(visited[d][i]){
            cout << i << endl;
            break;
        }
    }
    if(i==(1<<10))
        cout << -1 << endl;
    
    return 0;
}
