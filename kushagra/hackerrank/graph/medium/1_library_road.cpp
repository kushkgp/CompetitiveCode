#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

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

int main() {
    int q;
    cin >> q;
    vi A(100001);
    while(q--){
        int n,m,croad, clib;
        cin >> n >> m >> clib >> croad;
        // cout << m << "-----------------------------\n";
        int mi = n;
        while(mi--){
            A[mi+1]=mi+1;
        }
        // for(int i=1;i<=m;i++){
        //     cout << i << ":" << A[i] << " ";
        // }
        // cout << endl;
        mi = m;
        while(mi--){
            int u,v;
            cin >> u >> v;
            union_u(A,u,v);
        }
        if(clib < croad){
            cout << clib*(long long)n << endl;
        }
        else{
            // for(int i=1;i<=n;i++){
            //     cout << i << ":" << A[i] << " ";
            // }
            // cout << endl;
            int cnt = 0;
            for(int i=1;i<=n;i++){
                // cout << A[i] << " ";
                if(A[i]==i)
                    cnt++;
            }
            // cout << endl;
            // cout << cnt << " ";
            cout << ((long long)cnt)*clib + (n-cnt)*(long long)croad << endl;
        }
    }
    return 0;
}
