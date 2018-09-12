#include <bits/stdc++.h>
#define ff first
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
vector<string> split_string(string);

ll fairCut(int k, vector<int> a) {
    vv<ll> dp(a.size()+1,v<ll>(k+1,(ll)(1)<<58));
    sort(a.begin(), a.end());
    int n = a.size();
    int m = a[0];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int f = i%2;
        int g = f^1;
        a[i-1]-=m;
        for(int j = 0; j <= min(k,i); j++ ){
            if(j)
                dp[i][j] = min(dp[i-1][j-1]+(ll)a[i-1]*(2*(i-j)-(n-k)), dp[i-1][j]+(ll)a[i-1]*(2*j-k));
            else
                dp[i][j] = dp[i-1][j]+(ll)a[i-1]*(-k);
        }
    }
    return dp[a.size()][k];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    ll result = fairCut(k, arr);

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
