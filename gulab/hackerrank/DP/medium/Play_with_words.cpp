#include <bits/stdc++.h>

using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
ll playWithWords(string s) {
    vv<int> dp(s.size()+1,v<int>(s.size()+1,0));
    for(int i = 1; i <= s.size(); i++){
        dp[i][i] = 1;
    }
    for(int l = 2; l <= s.size(); l++){
        for(int i = 1; i <= s.size()-l+1; i++){
            int j = i+l-1;
            if(s[i-1] == s[j-1])
                dp[i][j] = dp[i+1][j-1]+2;
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }
    ll m = 0;
    for(int i = 1; i < s.size(); i++){
        m = max(m,(ll)dp[1][i]*dp[i+1][s.size()]);
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    ll result = playWithWords(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
