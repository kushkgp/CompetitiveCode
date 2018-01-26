#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1E9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define FOR(i, n) for (int i = 0; i < n; i++)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int,ll> pill;
typedef vector<pill> vpill;

void FloydWarshall(vvi &mat){
    int n = mat.size();
    FOR(k,n){
        FOR(i,n){
            FOR(j,n){
                if(mat[i][j] > mat[i][k]+mat[k][j])
                    mat[i][j] = mat[i][k]+mat[k][j];
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vvi mat(n,vi(n,inf));
    FOR(i,n){
        mat[i][i] = 0;
    }
    FOR(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        mat[a][b] = c;
    }
    FloydWarshall(mat);
    int q;
    cin >> q;
    FOR(i,q){
        int a,b;
        cin >> a >> b;
        --a;--b;
        if(mat[a][b]==inf)
            cout << -1 << endl;
        else
            cout << mat[a][b] << endl;
    }
    
    return 0;
}
