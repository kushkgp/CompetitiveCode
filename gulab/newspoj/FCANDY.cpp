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


int ans(const vpii v, int sum, int n){
	bool dp[sum+1][2];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	int f = 1;
	for (int i = 0; i < n; ++i,f^=1)
	{
		for(int st = 0; st < v[i].ss; st++){
			int count = 0;
			for (int j = 0;st+j*v[i].ss<=sum; ++j)
			{
				if(dp[st + j*v[i].ss][f^1])
					count++;
				if(count)
					dp[st + j*v[i].ss][f] = 1;
				if(j-v[i].ff>=0&&dp[st + (j-v[i].ff)*v[i].ss][f^1])
					count--;
			}
		}
	}
	f^=1;
	for (int i = sum ; i >= 0; --i)
	{
		if(dp[i][f])
			return (sum-i)<<1;
	}
}

int main(){
	int n;
	cin>>n;
	vpii v;
	v.resize(n);
	int sum = 0;
	for (int i = 0; i < n; ++i){
		cin>>v[i].ff>>v[i].ss;
		sum+=v[i].ff*v[i].ss;
	}
	cout<<(ans(v,sum>>1,n) + (sum&1))<<endl;
	return 0;
}