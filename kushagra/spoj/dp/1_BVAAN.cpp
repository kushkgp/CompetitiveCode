/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t;
	cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		int k;
		cin >> k;
		int p,q;
		p = a.length();
		q = b.length();

		vector<vvi> dp(p+1,vvi(q+1,vi(k+1,0)));
		F1(i,0,p){
			F1(j,0,q){
				F1(t,1,k){
					if(i==0 || j==0){
						dp[i][j][t] = -inf;
						continue;
					}
					if(a[i-1] == b[j-1]){
						dp[i][j][t] = max(dp[i-1][j-1][t-1] + a[i-1] , dp[i-1][j-1][t]);
					}
					else{
						dp[i][j][t] = max(dp[i][j-1][t], dp[i-1][j][t]);
					}
				}
			}
		}
		cout << (dp[p][q][k]>0?dp[p][q][k]:0) << endl;
	}
}