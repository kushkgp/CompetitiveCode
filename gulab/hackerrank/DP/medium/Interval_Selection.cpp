#include <bits/stdc++.h>
#define mp make_pair
#define ff first
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef pair<int,int> pii;
/*
 * Complete the intervalSelection function below.
 */
int intervalSelection(vector<vector<int>> I) {
    auto less_than = [&](const v<int> & a, const v<int> & b)->bool{
        return a[1]==b[1]? a[0]>b[0]:a[1]<b[1];
    };
    sort(I.begin(), I.end(), less_than);
    int ans = 0;
    set<pair<pii,int>> curr;
    for(int i = I.size()-1; i >= 0; i-- ){
        int end = I[i][1];
        while(!curr.empty() && end < -curr.begin()->ff.ff)
            curr.erase(curr.begin());
        if(curr.size()==2){
            auto it = curr.begin();
            it++;
            if(-it->ff.ff < I[i][0]){
                curr.erase(it);
                curr.insert(mp(mp(-I[i][0],I[i][1]), i));
            }
        }
        else{
            curr.insert(mp(mp(-I[i][0],I[i][1]), i));
            ans++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> intervals(n);
        for (int intervals_row_itr = 0; intervals_row_itr < n; intervals_row_itr++) {
            intervals[intervals_row_itr].resize(2);

            for (int intervals_column_itr = 0; intervals_column_itr < 2; intervals_column_itr++) {
                cin >> intervals[intervals_row_itr][intervals_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = intervalSelection(intervals);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
