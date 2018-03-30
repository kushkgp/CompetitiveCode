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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n,l,d;
		cin>>n>>l>>d;
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		vvi dp(2,vi(2,0));
		dp[1][0] = 1;
		F1(i,0,n-1){
			int c = i<l?(s[i]=='1'?1:0):0;
			if(c){
				dp[i&1][0] = dp[(i-1)&1][0];
				dp[i&1][1] = dp[(i-1)&1][1] + dp[(i-1)&1][0];
			}
			else{
				dp[i&1][0] = dp[(i-1)&1][0] + dp[(i-1)&1][1];
				dp[i&1][1] = dp[(i-1)&1][1];
			}
			if(i%20){
				dp[i&1][0]%=d;
				dp[i&1][1]%=d;
			}
		}
		cout<<dp[(n-1)&1][0]%d<<endl;
	}
}