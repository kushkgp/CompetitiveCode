#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef pair<int,int> pii;
vector<string> split_string(string);

int coinOnTheTable(int m, int k, v<string> b) {
    int n = b.size();
    pii f;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(b[i][j] == '*')
                f = mp(i,j);
    if(k < f.ff+f.ss)
        return -1;
    vv<v<int>> dp(n,vv<int>(m,v<int>(k+1,INT_MAX)));
    auto find = [&](int t,int x, int y, char c)->int{
        if(x >= 0 && x < n && y >= 0 && y < m && b[x][y]!='*'){
            if(c == b[x][y])
                return dp[x][y][t];
            if(dp[x][y][t] != INT_MAX)
                return dp[x][y][t]+1;
        }
        return INT_MAX;
    };
    dp[0][0][0] = 0;
    int ans = f.ff+f.ss;
    //cout<<ans<<endl;
    for(int t = 1; t <= k; t++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j][t] = min(dp[i][j][t],find(t-1,i+1,j,'U'));
                dp[i][j][t] = min(dp[i][j][t],find(t-1,i-1,j,'D'));
                dp[i][j][t] = min(dp[i][j][t],find(t-1,i,j-1,'R'));
                dp[i][j][t] = min(dp[i][j][t],find(t-1,i,j+1,'L'));
            }
        }
        ans = min(ans,dp[f.ff][f.ss][t]);
        //cout<<ans<<endl;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector<string> board(n);

    for (int board_itr = 0; board_itr < n; board_itr++) {
        string board_item;
        getline(cin, board_item);

        board[board_itr] = board_item;
    }

    int result = coinOnTheTable(m, k, board);

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
