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

int check(const vi &v, int n, int m){
	int x = 0;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum+=v[i];
		if(sum>m||i==n-1){
			x++;
			sum = a[i];
		}
	}
	return x;
}

int bs(const vi & v,int n,int key){
	int x=-1;
	int mid,l=0,r=n-1;
	while(l<=r){
		mid=(l+r)/2;
		if(v[mid].e<=key){
			x=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return x;
}

int ans(const vi &v, int t){
	int dp[v.size()][2];
	int n = v.size();
	dp[0][1] = v[0];
	for (int i = 1; i < n; ++i)
		dp[i][1]=dp[i-1][1]+v[i];
	for (int k = 2; k <= t; ++k)
	{
		for (int i = k-1; i < n; ++i)
		{
			int m=0,dp1;
			dp[i][k%2] = dp[i][(k+1)%2];
			for (int p = i; p > k-2; --p)
			{
				m+=v[p];
				dp1=max(m,dp[p-1][(k+1)%2]);
				dp[i][k%2]=min(dp1,dp[i][k%2]);
			}
		}
	}
	return dp[n-1][t%2];
}

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vi v;
		v.resize(n,0);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		cout<<ans(v,k)<<endl;
	}
}