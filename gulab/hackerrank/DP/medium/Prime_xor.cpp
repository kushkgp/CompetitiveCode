#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef long long ll;
vector<string> split_string(string);

// Complete the primeXor function below.
int primeXor(vector<int> a) {
    vv<ll> dp(2,v<ll>(1<<13,0));
    dp[0][0] = 1;
    v<int> arr(1001,0);
    for(int i = 0; i < a.size(); i++){
        int x = a[i]-3500;
        arr[x]+=1;
    }
    int f = 1, g;
    for(int i = 0; i < arr.size(); i++){
        if(!arr[i])
            continue;
        g = f^1;
        for(int j = 0; j < (1<<13); j++){
            dp[f][j] = ((dp[g][j]*((2+arr[i])>>1))%mod+(dp[g][j^(i+3500)]*((arr[i]+1)>>1))%mod)%mod;
        }
        f^=1;
    }
    v<int> seive(1<<13,0);
    v<int> primes;
    for(int i = 2; i < (1<<13); i++){
        if(!seive[i]){
            primes.pb(i);
            for(int j = i; j*i < (1<<13); j++)
                seive[j*i] = 1;
        }
    }
    
    int last_ind = f^1;
    ll ans = 0;
    for(int i = 0; i < primes.size();i++){
        ans+=dp[last_ind][primes[i]];
        ans%=mod;
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

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

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
