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

inline int is_present(set<int> &s, int x){
    return (s.count(x)>=1);
}

void bfs(int s, vi &dist, vector<set<int> > &adj){
    int n = adj.size();
    
    deque<int> q;
    set<int> notD;
    for(int i=0;i<n;i++)
        notD.insert(i);
    
    dist[s] = 0;
    notD.erase(s);
    q.pb(s);
    
    while(!q.empty()){
        int crt = q.front();
        q.pop_front();
        // cout << crt << " : ";
        for(auto it = notD.begin();it!=notD.end();it++){
            int to = *it;
            // cout << to << " ";
            if(adj[crt].find(to)==adj[crt].end()){
                q.push_back(to);
                // cout << to << " ";
                dist[to] = dist[crt] + 1;
                notD.erase(it);
                // it--;
            }
        }
        // cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<set<int> > adj(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            a--;b--;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        int s;
        cin >> s;
        s--;
        vi dist(n,INT_MAX);
        bfs(s, dist, adj);
        for(int i=0;i<n;i++){
            if(i==s)
                continue;
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
