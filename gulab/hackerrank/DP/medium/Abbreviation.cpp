#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    vector<vector<int> > dp(a.size()+1, vector<int>(b.size()+1,0));
    dp[0][0] = 1;
    for(int i = 1; i <= a.size(); i++){
        dp[i][0] = 1;
        for(int j = 1; j <= b.size(); j++){
            if( a[i-1]-'0' == b[j-1]-'0' || a[i-1]-'0'-32==b[j-1]-'0')
                dp[i][j] = dp[i-1][j-1];
            dp[i][j]|=((tolower(a[i-1])!=a[i-1])?0:dp[i-1][j]);
        }
    }
    return dp[a.size()][b.size()]?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
