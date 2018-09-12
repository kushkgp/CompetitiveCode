#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
vector<string> split_string(string);

// Complete the cost function below.
int cost(vector<int> B) {
    vvi dp(2,vi(100,0));
    //cout<<B.size()<<endl;
    for(int i = 1; i < B.size(); i++){
        int f = i%2;
        int g = f^1;
        auto maxi = [](const pii & a, const pii &b)->pii{
            pii temp = a;
            if( a.ff + abs(b.ss-a.ss) < b.ff)
                temp = b;
            return temp;
        };
        pii m = mp(dp[g][0],0);
        for(int j = 0; j < 100; j++){
            if(j > B[i]-1){
                dp[f][j] = INT_MIN;
                continue;
            }
            if( j < B[i-1])
                m =  maxi(m,mp(dp[g][j],j));
            dp[f][j] = m.ff + abs(m.ss - j);
        }
        m = mp(dp[g][B[i-1]-1],B[i-1]-1);
        for(int j = B[i]-1; j >= 0; j--){
            if( j < B[i-1])
                m =  maxi(m,mp(dp[g][j],j));
            dp[f][j] = max(dp[f][j],m.ff + abs(m.ss - j));
        }
        /*for(int i = 0 ; i < 3; i++)
            cout<<dp[f][i]<<" ";
        cout<<endl;*/
    }
    int maxi = 0;
    for(int i = 0; i < 100; i++){
        maxi = max(maxi, dp[(B.size()-1)%2][i]);
    }
    return maxi;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);

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
