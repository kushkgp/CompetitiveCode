#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pr pair<int,int>
#define pp pair<pr,pr>
#define vpp vector<pp>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int find(vi &A, int a){
    if(A[a]!=a){
        A[a] = find(A,A[a]);
    }
    return A[a];
}
int union_a(vi &A, int x, int y){
    int i = find(A,x);
    int j = find(A,y);
    if(i>j){
        int t = i;
        i = j;
        j = t;
    }
    A[j] = i;
    return i;
}
int main() {
    int n, m;
    cin >> n >> m;
    vi A(n+1);
    vpp edges;
    for(int i=0;i<=n;i++)
        A[i]=i;
    for(int i=0;i<m;i++){
        int x,y,r;
        cin >> x >> y >> r;
        edges.pb(mp(mp(r,x+y+r),mp(x,y)));
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto it = edges.begin();it<edges.end();it++){
        pp crt = *it;
        if(find(A,crt.ss.ff)!=find(A,crt.ss.ss)){
            ans+=crt.ff.ff;
            union_a(A,crt.ss.ff,crt.ss.ss);
        }
    }
    cout << ans << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
