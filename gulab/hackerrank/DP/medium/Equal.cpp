#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equal function below.
int equal(vector<int> a) {
    int m = INT_MAX;
    for(int i = 0; i < a.size(); i++)
        m = min(m, a[i]);
    int ans = INT_MAX;
    vector<int> b(a);
    for(int j = 0; j < 5; j++){
        int mi = m - j;
        int temp = 0;
        for(int i = 0; i < a.size(); i++){
            a[i] -= mi;
            temp  += a[i]/5;
            a[i]  = a[i]%5;
            temp  += (a[i]>2)? 2:(a[i])?1:0;
        }
        a = b;
        ans = min(ans, temp);
    }
    return ans;
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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

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
