#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;

void dfs(int u, v<int> & vis, vv<int> &adj, vv<ll> & dp ){
    vis[u] = 1;
    v<int> child;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v]){
            dfs(v,vis,adj,dp);
            child.pb(v);
        }
    }
    ll a = 1, b = 1, c = 1, d = 1;
    for(int i = 0; i < child.size(); i++){
        int v = child[i];
        a*=(dp[v][1]+dp[v][0]+dp[v][3]);
        b*=dp[v][3];
        c*=(dp[v][1]+dp[v][2]+dp[v][3]);
        d*=dp[v][1];
        a%=mod;
        b%=mod;
        c%=mod;
        d%=mod;
        if(u==2)
            cout<<c<<endl;
    }
    dp[u][1] = (a-b+mod)%mod;
    dp[u][3] = (c-d+mod)%mod;
    dp[u][0] = b;
    dp[u][2] = d;
}

// Complete the kingdomDivision function below.
int kingdomDivision(int n, vector<vector<int>> roads) {
    vv<int> adj(n);
    for(int i = 0; i < roads.size(); i++){
        adj[--roads[i][0]].pb(--roads[i][1]);
        adj[roads[i][1]].pb(roads[i][0]);
    }
    v<int> vis(n,0);
    vv<ll> dp(n,v<ll>(4,0));
    dfs(0,vis,adj,dp);
   /* for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[i].size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return (dp[0][1]+dp[0][3])%mod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> roads(n-1);
    for (int i = 0; i < n-1; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = kingdomDivision(n, roads);

    fout << result << "\n";

    fout.close();

    return 0;
}
