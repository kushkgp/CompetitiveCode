#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod 1000000007
typedef long long ll;
int isseive = 0;
int seive[100000];
vector<int> primes;

void fillseive(){
    memset(seive, 0 , sizeof(seive));
    for(int p = 2; p*p < 100000; p++){
        if(!seive[p]){
            primes.pb(p);
            for(int j = p; j * p < 100000; j++){
                seive[j*p] = 1;
            }
        }
    }
    isseive = 1;
}

int pow(int a, int p, int m){
    if(!p)
        return 1%m;
    ll x = pow(a,p>>1,m);
    x*=x;
    x%=m;
    x*=(p&1)?a:1;
    x%=m;
    return x;
}

int findphi(int x){
    int phi = x;
    for(int i = 0; i < primes.size() && primes[i] <= x; i++){
        // cout << primes[i] << " ";
        if(x%primes[i]==0){
            while(x%primes[i] == 0)
                x/=primes[i];
            phi-=phi/primes[i];
        }
    }
    if(x!=1)
        phi-=phi/x;
    return phi;
}

int product_of_divisor(int x){
    int n =x;
    ll result = 1;
    int phi = findphi(x);
    int phimod      = findphi(mod);
    int phiphimod   = findphi(phimod);
    int issquare    = 1;
    for(int i = 0; i < primes.size() && primes[i] <= x; i++){
        if(x%primes[i] == 0){
            int k = 1;
            while(x%primes[i] == 0){
                k++;
                x/=primes[i];
            }
            if(!(k&1))
                issquare = 0;
            result*=k;
            result%=phimod;
        }
    }
    int ans;
    if(issquare){
        result=(result+1)>>1;
        ans = ((ll)pow(n,result,mod)*pow(sqrt(n),mod-2,mod))%mod;
    }
    else{
        result>>=1;
        ans = pow(n,result,mod);
    }
    return ans;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    if(!isseive)
        fillseive();
    
    vector<pair<int,ll> > C(A.size());
    vector<int> l,r;
    stack<pair<int,int> >s;
    for(int i = 0; i < A.size(); i++){
        while(!s.empty() && s.top().ff <= A[i] )
            s.pop();
        int x = 1;
        if(!s.empty())
            x+=i - s.top().ss-1;
        else
            x+=i;
        C[i] = mp(A[i], x);
        // cout<<"hi:"<<A[i]<<" "<<x<<endl;
        s.push(mp(A[i], i));
    }
    while(!s.empty())
        s.pop();
    for(int i = A.size()-1; i >= 0; i--){
        while(!s.empty() && s.top().ff < A[i] )
            s.pop();
        int x = 1;
        if(!s.empty())
            x+=s.top().ss - i-1;
        else
            x+=A.size()-1-i;
        C[i] = mp(A[i], C[i].ss*x);
        s.push(mp(A[i], i));
    }
    for(int i = 0; i < C.size(); i++)
        C[i].ff = product_of_divisor(C[i].ff);
    auto gt = [](const pair<int,int> &a, const pair<int,int> &b){
        return a.ff==b.ff?a.ss>b.ss:a.ff>b.ff;
    };
    sort(C.begin(),C.end(),gt);
    vector<int> rank(C.size());
    rank[0] = C[0].ss;
    // cout<<C[0].ff<<" "<<C[0].ss<<endl;
    for(int i = 1; i < C.size(); i++){
        // cout<<C[i].ff<<" "<<C[i].ss<<endl;
        C[i].ss+=C[i-1].ss;
        rank[i] = C[i].ss;
    }
    // cout<<endl;
    vector<int> ans(B.size());
    for(int i = 0; i < B.size(); i++)
        ans[i]  += C[lower_bound(rank.begin(), rank.end(), B[i]) - rank.begin()].ff;
    
    return ans;
}

int main(){
    if(!isseive)
        fillseive();
    vector<int> a,b;
    a.pb(5);
    a.pb(3);
    b.pb(1);
    b.pb(3);

    vector<int> ans = solve(a,b);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}