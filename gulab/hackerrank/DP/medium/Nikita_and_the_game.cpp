#include <bits/stdc++.h>

using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv =  v<v<X>>;
typedef long long ll;
vector<string> split_string(string);


int finddp(v<ll> & p, int i, int j, ll v, int prev){
    if( (v&1) || i==j )
        return 0;
    /*for(int k = i; k <= j; k++)
        cout<<p[k]<<" ";
    cout<<endl;*/
    int x = lower_bound(p.begin()+i,p.begin()+j+1,(v>>1)+prev) - p.begin();
    if( p[x] == prev+(v>>1) )
        return 1+max(finddp(p,i,x,v>>1,prev),finddp(p,x+1,j,v>>1,prev+(v>>1)));
    else
        return 0;
}

int arraySplitting(vector<int> a) {
    int n = a.size();
    v<ll> p(a.size(),0);
    p[0] =  a[0];
    for(int i = 1; i < a.size(); i++)
        p[i]=p[i-1]+a[i];
    if(p[a.size()-1] == 0)
        return a.size()-1;
    return finddp(p,0,n-1,p[a.size()-1],0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = arraySplitting(arr);

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
