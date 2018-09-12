#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
vector<string> split_string(string);

ll pow(int a, int p, int m){
    if(p == 0)
        return 1%m;
    ll x = pow(a,p>>1,m);
    x*=x;
    x%=m;
    x*=p&1?a:1;
    return x%m;
}

int legoBlocks(int n, int m) {
    v<ll> dp(m+1,0);
    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= 4 && i-j>=0; j++){
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }

    for(int i = 0; i <= m; i++){
        dp[i] = pow(dp[i],n,mod);
    }
        //cout<<dp[m]<<endl;
    v<ll> dp2(m+1,0);
    for(int i = 1; i <= m; i++){
        dp2[i] = dp[i];
        for(int j = 1; j < i; j++){
            dp2[i]+=mod-(dp2[i-j]*dp[j])%mod;
            dp2[i]%=mod;
        }
    }
    return dp2[m];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
