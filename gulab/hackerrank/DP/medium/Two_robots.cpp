#include <bits/stdc++.h>

using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
vector<string> split_string(string);

/*
 * Complete the twoRobots function below.
 */
int twoRobots(int m, vector<vector<int>> q) {
    int n = q.size();
    vv<int> dp(n,v<int>(m,INT_MAX));
    for(int i = 0; i < m; i++)
        dp[0][i] = abs(q[0][0]- q[0][1]);

    for(int i = 0; i < q.size(); i++)
        q[i][0]--,q[i][1]--;
    
    for(int i = 0; i < q.size()-1; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j]!=INT_MAX){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + abs(q[i][1]-q[i+1][0]) + abs(q[i+1][1]-q[i+1][0]));
                dp[i+1][q[i][1]] = min(dp[i+1][q[i][1]], dp[i][j] + abs(q[i+1][1]-q[i+1][0]) + abs(j-q[i+1][0]));
            } 
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; i++)
        ans = min(ans, dp[n-1][i]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        string mn_temp;
        getline(cin, mn_temp);

        vector<string> mn = split_string(mn_temp);

        int m = stoi(mn[0]);

        int n = stoi(mn[1]);

        vector<vector<int>> queries(n);
        for (int queries_row_itr = 0; queries_row_itr < n; queries_row_itr++) {
            queries[queries_row_itr].resize(2);

            for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
                cin >> queries[queries_row_itr][queries_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = twoRobots(m, queries);

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
