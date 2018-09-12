#include <bits/stdc++.h>
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
vector<string> split_string(string);

vector<int> specialSubCubes(vector<int> a, int n) {
    vv<vv<int>> dp(2,v<vv<int>>(n,vv<int>(n,v<int>(n))));
    v<int> ans;
    int x = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++){
                dp[1][i][j][k] = a[i*n*n+j*n+k];
                if(dp[1][i][j][k] == 1)
                    x++;
            }
    ans.pb(x);
    for(int l = 2; l <= n; l++){
        int f = l%2;
        int g = f^1;
        x = 0;
        for(int i = 0; i < n-l+1; i++)
            for(int j = 0; j < n-l+1; j++)
                for(int k = 0; k < n-l+1; k++){
                    int m = INT_MIN;
                    m = max(m, dp[g][i][j][k]);
                    m = max(m, dp[g][i+1][j][k]);
                    m = max(m, dp[g][i][j+1][k]);
                    m = max(m, dp[g][i+1][j+1][k]);
                    
                    m = max(m, dp[g][i][j][k+1]);
                    m = max(m, dp[g][i+1][j][k+1]);
                    m = max(m, dp[g][i][j+1][k+1]);
                    m = max(m, dp[g][i+1][j+1][k+1]);
                    dp[f][i][j][k] = m;
                    if(m==l)
                        x++;
                }
        ans.pb(x);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cube_temp_temp;
        getline(cin, cube_temp_temp);

        vector<string> cube_temp = split_string(cube_temp_temp);

        vector<int> cube(n*n*n);

        for (int cube_itr = 0; cube_itr < n*n*n; cube_itr++) {
            int cube_item = stoi(cube_temp[cube_itr]);

            cube[cube_itr] = cube_item;
        }

        vector<int> result = specialSubCubes(cube, n);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
