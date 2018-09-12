#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
vector<string> split_string(string);

/*
 * Complete the twoSubsequences function below.
 */
int twoSubsequences(vector<int> x, int r, int s) {
    if((r+s)%2 == 1 || r < s || (!r&&!s))
        return 0;
    int n = x.size();
    int a = (r+s)>>1;
    int b = (r-s)>>1;
    int MAX = max(a,b);
    int dp[2][n+1][MAX+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        int f = i%2;
        int g = f^1;
        for(int j = 0; j <= i; j++){
            for(int sum = 0; sum <= MAX; sum++){
                dp[f][j][sum]=dp[g][j][sum];
                if(j && sum>=x[i-1]){
                    dp[f][j][sum]+=dp[g][j-1][sum-x[i-1]];
                }
                if(dp[f][j][sum] >= mod)
                    dp[f][j][sum]-=mod;
            }
        }
    }
    int ans = 0;     
    for(int i = 0; i <= n; i++){
        ans+=((ll)dp[n%2][i][a]*dp[n%2][i][b])%mod;
        if(ans>=mod)
            ans-=mod;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mrs_temp;
    getline(cin, mrs_temp);

    vector<string> mrs = split_string(mrs_temp);

    int m = stoi(mrs[0]);

    int r = stoi(mrs[1]);

    int s = stoi(mrs[2]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<int> x(m);

    for (int x_itr = 0; x_itr < m; x_itr++) {
        int x_item = stoi(x_temp[x_itr]);

        x[x_itr] = x_item;
    }

    int result = twoSubsequences(x, r, s);

    fout << result << "\n";

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
