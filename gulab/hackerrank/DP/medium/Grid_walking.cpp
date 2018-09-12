#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
vector<string> split_string(string);

int gridWalking(int m, vector<int> x, vector<int> D) {
    int n = D.size();
    int dp[m+1][n][100];
    memset(dp, 0, sizeof(dp));
    int ways[D.size()][m+1];
    memset(ways, 0, sizeof(ways));
    for(int i = 0; i < D.size(); i++){
        dp[0][i][--x[i]] = 1;
        ways[i][0] = 1;
        for(int k = 1; k <= m; k++){
            for(int j = 0; j < D[i]; j++){
                dp[k][i][j] = ((j+1<D[i]?dp[k-1][i][j+1]:0)+(j-1>=0?dp[k-1][i][j-1]:0))%mod;  
                ways[i][k]+=dp[k][i][j];
                ways[i][k]%=mod;
            }
        }
    }
    int ncr[301][301];
    ncr[1][1] = 1;
    ncr[1][0] = 1;
    for(int i = 2; i <= 300; i++){
        for(int j = 0; j <= i; j++){
            ncr[i][j] = (ncr[i-1][j] + (j>0?ncr[i-1][j-1]:0))%mod;
        }
    }
    int ans[m+1];
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for(int i = 0; i < D.size(); i++){
        for(int k = m; k > 0; k--){
            int temp = 0;
            for(int j = 0; j <= k; j++){
                temp+= (((ll)ans[j]*ways[i][k-j])%mod*ncr[k][j])%mod;
                temp%= mod;
            }
            ans[k] = temp;
        }
    }
    return ans[m];
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

        string x_temp_temp;
        getline(cin, x_temp_temp);

        vector<string> x_temp = split_string(x_temp_temp);

        vector<int> x(n);

        for (int x_itr = 0; x_itr < n; x_itr++) {
            int x_item = stoi(x_temp[x_itr]);

            x[x_itr] = x_item;
        }

        string D_temp_temp;
        getline(cin, D_temp_temp);

        vector<string> D_temp = split_string(D_temp_temp);

        vector<int> D(n);

        for (int D_itr = 0; D_itr < n; D_itr++) {
            int D_item = stoi(D_temp[D_itr]);

            D[D_itr] = D_item;
        }

        int result = gridWalking(m, x, D);

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
