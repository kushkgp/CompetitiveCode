#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
int find(vi &A, int i){
    if(A[i]!=i){
        A[i] = find(A,A[i]);
    }
    return A[i];
}
int union_u(vi &A, int a, int b){
    int i = find(A, a);
    int j = find(A, b);
    if(i>j){
        int t = i;
        i = j;
        j = t;
    }
    if(i!=j){
        A[j]=A[i];
    }
    return A[i];
}
int main()
{ 
    int n,p;
    cin >> n >> p;
    
    vi A(n);
    for(int i=0;i<n;i++){
        A[i]=i;
    }
    for(int i=0;i<p;i++){
        int u,v;
        cin >> u >> v;
        union_u(A,u,v);
    }
    vi cnt(n,0);
    for(int i=0;i<n;i++){
        find(A,i);
        cnt[A[i]]++;
    }
    long long whole, ind;
    whole = ind = 0;
    for(int i=0;i<n;i++){
        if(A[i]==i){
            whole+=cnt[i];
            ind += (cnt[i]*(long long)cnt[i]);
        }
    }
    cout << (whole*whole - ind)/2 << endl;
    return 0;
}
