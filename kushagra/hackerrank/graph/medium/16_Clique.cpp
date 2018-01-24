#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_max_edges(int n, int r){
    ll m = (ll)n*n;
    int x1 = n/r + 1;
    int x2 = n/r;
    m -= (ll)(n%r)*x1*x1;
    m -= (ll)(r-n%r)*x2*x2;
    m=m>>1;
    return m;
}
int bin_search(int l, int r, int x, int n){
    if(l==r)
        return l;
    int mid = (l+r)/2;
    ll e = get_max_edges(n, mid);
    if(e < x)
        return bin_search(mid+1, r, x, n);
    return bin_search(l,mid,x,n);
}
int min_clique(int n, int m){
    return bin_search(0,n,m,n);
}
int main() {
    int t;
    cin >> t ;
    while(t--){
        int n , m;
        cin >> n >> m;
        cout << min_clique(n,m) << endl;
    }
    return 0;
}
