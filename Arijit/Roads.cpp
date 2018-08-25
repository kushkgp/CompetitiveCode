#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(c) (c).begin(),(c).end()

typedef vector<long long> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;
typedef vector<pair<int, pii > > vpip;

int find_u(vi &A, int i){
    if(A[i]!=i){
        A[i]=find_u(A,A[i]);
    }
    return A[i];
}

int union_u(vi &A, int x, int y){
    int i = find_u(A,x);
    int j = find_u(A,y);
    if(i>j){
        int t = i;
        i = j;
        j = t;
    }
    if(i!=j){
        A[j] = A[i];
    }
    return A[i];
}

int kruskal(vpip &el, vvp &adj, int n){
    sort(el.begin(),el.end());
    vi A(n);
    FOR(i,n){
        A[i]=i;
    }
    int count = 0;
    FOR(i,el.size()){
        pair<int,pii> edge = el[i];
        //cout << "\n---" << edge.ss.ff << " " << edge.ss.ss << " " << edge.ff << " " ;
        int x,y;
        x = find_u(A,(edge.ss.ff));
        y = find_u(A,edge.ss.ss);
        if(x==y)
            continue;
        union_u(A,edge.ss.ss,edge.ss.ff);
        //cout << edge.ff << endl;
        adj[edge.ss.ss].pb(mp(edge.ss.ff,edge.ff));
        adj[edge.ss.ff].pb(mp(edge.ss.ss,edge.ff));
        //cout << edge.ss.ff << " " << edge.ss.ss;
        count++;
    }
    return count;
}

int dfs(vvp &adj, vi &vis, vl &count, int crt, int n){
    vis[crt] = 1;
    int child = 1;
    for(int i=0;i<adj[crt].size();i++){
        pii to = adj[crt][i];
        if(!vis[to.ff]){
            int x = dfs(adj, vis, count, to.ff, n);
            //cout << to.ss << " " << x*(n-x) << endl;
            count[to.ss] = (long long)x*(n-x);
            child += x;
        }
    }
    return child;
}
int main() {
    int n,m;
    cin >> n >> m;
    vvp adj(n);
    vpip el;
    FOR(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        el.pb(mp(c,mp(a,b)));
    }
    kruskal(el, adj, n);
    vi vis(n,0);
    vl count(m,0);
    dfs(adj, vis, count, 0, n);
    string ans = "";
    string temp = "";
    long long left = 0;
    for(int i=0;i<m;i++){
    	cout<<i<<" "<<count[i]<<endl;
        left += count[i];
        temp += to_string(left%2);
        if(left){
            ans += temp;
            temp = "";
        }
        left = (left>>1);
    }
    cout<<left<<" "<<ans<<endl;
    while(left){
        ans += to_string(left%2);
        left = left>>1;
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}