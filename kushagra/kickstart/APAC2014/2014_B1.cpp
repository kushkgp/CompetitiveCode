#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;

int main(){
	int t;
	cin >> t;
	int ans[101][101];
	int cnt = 1;
	while(t--){
		int M,N;
		cin >> M >> N;
		int crt = 0;
		for(int i=0;i<M;i++){
			ans[0][i] = 0;
		}
		ans[0][0] = 1;
		for(int n=1;n<=N;n++){
			for(int m=0;m<=M;m++){
				ans[n][m] = (((long long)((ans[n-1][m-1]+ans[n-1][m])%mod)*m)%mod + mod)%mod;
			}
		}
		cout << "Case #" << cnt << ": " << ans[N][M] << endl;
		cnt++;
	}
}