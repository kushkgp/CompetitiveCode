#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
vector<string> split_string(string);

/*
 * Complete the swapPermutation function below.
 */
vector<int> swapPermutation(int n, int k) {
    int dp[n][k+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        int x = 0;
        for(int j = 0; j <= k; j++){
            x+=dp[i-1][j];
            x-=(j>i?dp[i-1][j-i-1]:0);
            x%=mod;
            x+=mod;
            x%=mod;
            dp[i][j] = x;
        }
    }
    v<int> ans(2,0);
    for(int i = k; i >= 0; i-=2){
        ans[0]+=dp[n-1][i];
        ans[0]%=mod;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = (dp[i-1][j]+(j?((ll)i*dp[i-1][j-1])%mod:0))%mod;
        }
    }
    for(int i = 0; i <= k; i++){
        ans[1]+=dp[n-1][i];
        ans[1]%=mod;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<int> result = swapPermutation(n, k);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
