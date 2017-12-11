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
typedef vector<pii> vpii;

int ans1(const vi & v, int n){
	int dp[n][n];
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i <n-k ; ++i)
		{
			int j = i+k;
			dp[i][j]=0;
			if(k==1){
				dp[i][j] = max(v[i],v[j]);
				continue;
			}
			else if(k>1){
				dp[i][j]= v[i]+max(dp[i+2][j],dp[i+1][j-1]);
				dp[i][j]= max(dp[i][j],v[j]+max(dp[i][j-2],dp[i+1][j-1]));
			}
		}
	}
	return dp[0][n-1];
}

int ans2(const vi &v, int n){
	int dp[n][n];
	int sum[n];
	sum[0] = v[0];
	for (int i = 1; i < n; ++i)
		sum[i]=v[i]+sum[i-1];
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i <n-k ; ++i)
		{
			int j = i+k;
			dp[i][j]=0;
			if(k==1){
				dp[i][j] = max(v[i],v[j]);
				continue;
			}
			else if(k>1){
				dp[i][j]= v[i]+sum[j]-sum[i]-dp[i+1][j];
				int temp = sum[j-1];
				if(i)
					temp-=sum[i-1];
				dp[i][j]= max(dp[i][j],v[j]+temp-dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		cout<<ans1(v,n)<<" "<<ans2(v,n)<<endl;
	}
}