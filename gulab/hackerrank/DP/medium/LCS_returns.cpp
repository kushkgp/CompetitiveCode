#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef pair<int,int> pii;
int dp[5002][5002];
int dp2[5002][5002];
/*
 * Complete the tutzkiAndLcs function below.
 */
int tutzkiAndLcs(string & a, string & b) {
    int m = a.size(), n = b.size();
    for(int i = 0; i <= m+1; i++)
        for(int j = 0; j <= n+1; j++)
            dp[i][j] = dp2[i][j] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }

    for(int i = m; i >= 1; i-- )
        for(int j = n; j >= 1; j-- ){
            if(a[i-1] == b[j-1])
                dp2[i][j] = dp2[i+1][j+1]+1;
            else
                dp2[i][j] = max(dp2[i+1][j],dp2[i][j+1]);
        }
    int lcs = dp[m][n];
    set<char> x[m+1];
    //memset(x, 0, sizeof(x));
    for(int j = 1; j <= n; j++){
        for(int i = 0; i <= m; i++){
            if(dp[i][j-1]+dp2[i+1][j+1] == lcs)
                x[i].insert(b[j-1]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++){
            ans+=x[i].size();
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int result = tutzkiAndLcs(a, b);

    fout << result << "\n";

    fout.close();

    return 0;
}
