#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back


int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        vvi adj(1001);
        for(int a1 = 0; a1 < m; a1++){
            int u;
            int v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vi dist(1001,0);
        vi visited(1001,0);
        int s;
        cin >> s;
        queue<int> bfs_q;
        bfs_q.push(s);
        dist[s]=0;
        visited[s]=1;
        while(!bfs_q.empty()){
            int front = bfs_q.front();
            bfs_q.pop();
            for(int i=0;i<adj[front].size();i++){
                int crt = adj[front][i];
                if(!visited[crt]){
                    //cout << crt << " ";
                    dist[crt] = dist[front] + 1;
                    visited[crt]=1;
                    bfs_q.push(crt);
                }
            }
        }
        //cout << endl;
        for(int i=1;i<=n;i++){
            if(i==s)
                continue;
            if(dist[i]!=0)
                cout << 6*dist[i] << " ";
            if(dist[i]==0)
                cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}
