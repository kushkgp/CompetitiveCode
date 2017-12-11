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

int ans(const vi & v, int k, int x){
	int dp[k][x+1];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j <= x; ++j)
		{
			if(j>=v[i])
				dp[i][j]|=dp[i][j-v[i]];
			if(i)
				dp[i][j]|=dp[i-1][j];
		}
	}
	return dp[k-1][x];
}

int main(){
	int x,k;
	cin>>x>>k;
	vi v;
	v.resize(k);
	for (int i = 0; i < k; ++i)
		cin>>v[i];
	for (int i = 1; i < k; ++i)
		v[i]+=v[i-1];
	if(ans(v,k,x))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}