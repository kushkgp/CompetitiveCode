/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

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

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vi a(n);
		F1(i,0,n-1)
			cin>>a[i];
		vvi dp(n,vi(n));
		F1(l,0,(n-1))
			F1(i,0,(n-l-1)){
				int j = i+l;
				dp[i][j] = l+1;
				F1(m,(i+1),(j-1)){
					if(a[m]-a[i]==k && a[j]-a[m]==k && (m-1<i+1 || !dp[i+1][m-1]) && (j-1<m+1 || !dp[m+1][j-1])){
						dp[i][j]=0;
						break;
					}
				}
				F1(m,i,(j-1))
					dp[i][j] = min(dp[i][j],dp[i][m]+dp[m+1][j]);
			}
		printf("Case #%d: %d\n", cnt++, dp[0][n-1]);
	}
}