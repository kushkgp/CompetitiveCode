#include <bits/stdc++.h>
#define MAX 2670963
#define pb push_back
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;
typedef long long ll;
int isseive = 0;
int seive[MAX+1];
v<int> primes;

void fill_seive(){
    memset(seive,0,sizeof(seive));
    for(int i = 2; i <= MAX; i++){
        if(!seive[i]){
            primes.pb(i);
            for(int j = i; j <= MAX/i; j++){
                seive[j*i]=1;
            }
        }
    }
    isseive = 1;
}

// Complete the redJohn function below.
int redJohn(int n) {
    v<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        if(i>3)
            dp[i]+=dp[i-4];
    }
    if(!isseive)
        fill_seive();
    return (upper_bound(primes.begin(),primes.end(),dp[n]) - primes.begin());
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

        int result = redJohn(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
