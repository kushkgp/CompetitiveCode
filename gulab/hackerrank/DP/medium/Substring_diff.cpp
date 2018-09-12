#include <bits/stdc++.h>

using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
vector<string> split_string(string);

// Complete the substringDiff function below.
int substringDiff(int k, string a, string b) {
    int m = a.size(), n = b.size();
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    dp[m][n] = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j]==-1 || !i || !j){
                int mis = 0;
                int l = 0;
                for(; i+l < m && j+l < n ; l++){
                    if(a[i+l]!=b[j+l])
                        mis++;
                    if(mis>k)
                        break;
                }
                dp[i][j] = l;
                for(int x = 1; i+x<m && j+x<n; x++){
                    --l;
                    if(a[i+x-1]!=b[j+x-1]){
                        l++;
                        while(i+x+l<m && j+x+l<n && a[i+x+l]==b[j+x+l])
                            l++;
                    }
                    dp[i+x][j+x] = l;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string kS1S2_temp;
        getline(cin, kS1S2_temp);

        vector<string> kS1S2 = split_string(kS1S2_temp);

        int k = stoi(kS1S2[0]);

        string s1 = kS1S2[1];

        string s2 = kS1S2[2];

        int result = substringDiff(k, s1, s2);

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
