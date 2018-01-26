#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

int dfs_cnt(int crt, vvi &adj, vi &visited,vi &child){
    visited[crt] = 1;
    for(int i=0;i<adj[crt].size();i++){
        int x = adj[crt][i];
        if(!visited[x]){
            child[crt] += dfs_cnt(x,adj,visited,child);
        }
    }
    return child[crt];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi child(n+1,1);
    vi visited(n+1,0);
    dfs_cnt(1,adj,visited,child);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(child[i]%2==0)
            ans++;
    }
    cout << ans-1 << endl;
    return 0;
}
