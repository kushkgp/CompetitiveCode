#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
template <typename X> using v = vector<X>;
typedef long long ll;
int pow(int a, int p, int m){
    if(!p)
        return 1;
    ll x = pow(a,p>>1,m);
    x*=x;
    x%=m;
    x*= (p&1)?a:1;
    x%=m;
    return x;
}

// Complete the substrings function below.
int substrings(string n) {
    int inv9 = pow(9, mod  - 2, mod);
    ll ans = 0, powten = 1;
    for(int i = n.length()-1; i >= 0; i--){
        powten*=10;
        powten%=mod;
        ll temp = (i+1)*(n[i]-'0');
        temp*=inv9;
        temp%=mod;
        temp*=(powten-1);
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
