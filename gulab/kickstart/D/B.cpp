/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;
int dp[2001][2001];

int ans(int n, const vi & S, const vi & D, const vi & F, int Ts, int Tf){
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = INT_MAX;
		}
	}
	dp[1][0] = 0;
	// dp[1][1] = Ts>S[1]?ceil((double)(Ts-S[1])/F[1])*F[1]+S[1]:S[1];
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			int c1,c2;
			c1 = c2 = INT_MAX;
			if(k&&dp[i-1][k-1]!=INT_MAX){
				c1 = dp[i-1][k-1]+Ts<=S[i-1]?S[i-1]:dp[i-1][k-1]+Ts;
				c1-=S[i-1];
				c1 = ceil((double)c1/F[i-1])*F[i-1];
				c1+=S[i-1];
			}
			if(k < i-1 &&dp[i-1][k]!=INT_MAX){
				c2 = dp[i-1][k]<=S[i-1]?S[i-1]:dp[i-1][k];
				c2-=S[i-1];
				c2 = ceil((double)c2/F[i-1])*F[i-1];
				c2 += S[i-1];
			}
			dp[i][k] = min(c1,c2);
			if(dp[i][k]<INT_MAX)
				dp[i][k] += D[i-1];
		}
	}
	// return dp[5][4];
	int i;
	int result = -1;
	for ( i = n-1; i >=0; --i)
	{
		if(dp[n][i]<=Tf){
			result = i;
			break;
		}
	}
	return result;
}


int main(){
	int t;
	cin>>t;
	int cas = 1;
	while(t--){
		int n, Ts, Tf;
		cin>>n>>Ts>>Tf;
		vi D(n),F(n),S(n);
		for (int i = 1; i < n; ++i)
		{
			cin>>S[i]>>F[i]>>D[i];
		}
		cout<<"Case #"<<cas++<<": ";
		int result = ans(n,S,D,F,Ts,Tf);
		if(result!=-1)
			cout<<result<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}