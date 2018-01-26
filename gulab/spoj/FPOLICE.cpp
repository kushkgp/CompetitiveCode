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


void ans(const vvi & time, const vvi & r, int n, int T){
	ll dp[n][T+1];
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = LLONG_MAX;
	}
	dp[0][0] =0;
	for (int t = 1; t <= T; ++t)
	{
		for (int i = 0; i < n; ++i)
		{
			dp[i][t] = dp[i][t-1];
			for (int j = 0; j < n; ++j)
			{
				if(i==j)
					continue;
				if(t>=time[j][i]&&dp[j][t - time[j][i]]!=LLONG_MAX)
					dp[i][t] = min(dp[i][t],dp[j][t - time[j][i]] + r[j][i]);
			}
		}
	}
	int result = T;
	for (int i = T; i >= 1; --i)
	{
		if(dp[n-1][i]==dp[n-1][i-1])
			result--;
		else break; 
	}
	ll a = dp[n-1][T]==LLONG_MAX?-1:dp[n-1][T];
	cout<<a<<" ";
	if(a!=-1)
		cout<<result;
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,T;
		cin>>n>>T;
		vvi r,time;
		r.resize(n,vi(n));
		time.resize(n,vi(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin>>time[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin>>r[i][j];
		ans(time,r,n,T);
	}
}