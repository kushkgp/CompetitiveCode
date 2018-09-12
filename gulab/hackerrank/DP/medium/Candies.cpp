#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> a) {
    vector<int> l(a.size()),r(a.size());
    int x = 1;
    l[0] = 1;
    for(int i = 1; i < a.size(); i++)
        l[i] = a[i]>a[i-1]?l[i-1]+1:1;
    x = 1;
    r[a.size()-1]= 1;
    for(int i = n-2; i >= 0; i--)
        r[i] = a[i]>a[i+1]?r[i+1]+1:1;
    long ans = 0;
    for(int i = 0; i < a.size(); i++)
        ans+=max(l[i],r[i]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
