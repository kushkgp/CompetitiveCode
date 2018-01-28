/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

// 1-> x 2-> k 3->curr 4->iter

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,x,k;
		double a,b,c;
		cin>>n>>x>>k>>a>>b>>c;
		a/=100,b/=100,c/=100;
		long double dp[2][2][2][2];
		dp[0][0][0][0] = dp[0][1][0][0] = 1;
		dp[0][0][1][0] = dp[0][1][1][0] = 0;
		dp[1][0][0][0] = dp[1][1][0][0] = 0;
		dp[1][0][1][0] = dp[1][1][1][0] = 1;
		F1(i,1,n){
			int f = i%2;
			F1(j,0,1){
				dp[j][0][0][f] = a*(dp[j][0][0][!f]+dp[j][0][1][!f])+b*dp[j][0][0][!f]+c*dp[j][0][0][!f];
				dp[j][0][1][f] = b*(dp[j][0][1][!f])+c*(dp[j][0][1][!f]);
				
				dp[j][1][0][f] = a*dp[j][1][0][!f]+c*dp[j][1][1][!f];
				dp[j][1][1][f] = a*dp[j][1][1][!f]+b*(dp[j][1][0][!f]+dp[j][1][1][!f])+c*dp[j][1][0][!f];
			}
		}
		long double ans = 0;
		F1(i,0,30){
			int f = n%2;
			int xbit = !(!(x&(1<<i)));
			int kbit = !(!(k&(1<<i)));
			ans += (1<<i)*dp[xbit][kbit][1][f];
		}
		printf("Case #%d: %.10LF\n", cnt++, ans);
	}
}