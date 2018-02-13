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

int n, m, l;

int min(deque<pii> & q, int x, int k){
	int ind = q.empty()?0:q.back().ss+1;
	while(!q.empty() && q.back().ff >= x)
		q.pop_back();
	q.push_back(mp(x,ind));
	if(ind-q.front().ss>k-1)
		q.pop_front();
	return q.front().ff;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>n>>m>>l;
		v<pii> a(n);
		vi p(n);
		F1(i,0,n-1)
			cin>>a[i].ff>>a[i].ss>>p[i];
		vi dp(l+1,inf);
		dp[0] = 0;
		F1(i,0,n-1){
			deque<pii> q;
			int k = a[i].ss-a[i].ff+1;
			F2(j,l-a[i].ff,-k){
				int x = min(q,j>=0?dp[j]:inf,k);
				if(j<=l-a[i].ss)
					dp[j+a[i].ss]=min(dp[j+a[i].ss],x+p[i]);
			}
		}
		printf("Case #%d: ", cnt++);
		cout<<(dp[l]>m?"IMPOSSIBLE":to_string(dp[l]))<<endl;;
	}
}