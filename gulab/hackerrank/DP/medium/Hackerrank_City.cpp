#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
template <typename X> using v = vector<X>;
vector<string> split_string(string);

/*
 * Complete the hackerrankCity function below.
 */
int hackerrankCity(vector<int> A) {
    v<ll> N(2,0),S(2,0),D(2,0),M(2,0);
    N[1] = 1;
    for(int i = 0; i < A.size(); i++){
        int f = i&1;
        int g = f^1;
        N[f] = (N[g]<<2)+2;
        N[f]%=mod;
        M[f] = (M[g]<<1)+3*A[i];
        M[f]%=mod;
        D[f] = D[g]+2*(D[g]+(3*A[i]+M[g])*N[g])%mod+(D[g]+(2*A[i]+M[g])*N[g])%mod+(2*M[g]+3*A[i]);
        D[f]%=mod;
        S[f] =(S[g]<<2)+((2*D[g]+3*A[i]*N[g])<<2)+2*(N[g]*((2*A[i]*N[g]+2*D[g])%mod))%mod+4*(N[g]*((3*A[i]*N[g]+2*D[g])%mod))%mod + A[i];
        S[f]%=mod;
    }
    int lst = (A.size()-1)%2;
    cout<<N[lst]<<" "<<M[lst]<<" "<<D[lst]<<" "<<S[lst]<<endl;
    return S[(A.size()-1)%2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int A_count;
    cin >> A_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(A_count);

    for (int A_itr = 0; A_itr < A_count; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = hackerrankCity(A);

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
