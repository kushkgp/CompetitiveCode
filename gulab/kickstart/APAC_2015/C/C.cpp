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


int find(vi & dp, vvi & adj, int s){
	int pop = __builtin_popcount(s);
	if(pop==1)
		return 1;
	int & ret = dp[s];
	if(ret>=0)
		return ret;
	F1(i,0,15){
		if(s&(1<<i)){
			F1(j,0,i-1){
				if(s&(1<<j)){
					if((1<<adj[i][j])>=pop)
						return ret = 0;
				}
			}
		}
	}
	ret = 0;
	int half = __builtin_popcount(s)>>1;
	
	for(int i = s; i>0 && ret==0; i = (i-1)&s)
		if(__builtin_popcount(i)==half)
			ret = find(dp,adj,i)&find(dp,adj,s&(~i));
	return ret;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vvi adj(1<<n,vi(1<<n,0));
		vi dp(1<<(1<<n),-1);
		F1(i,0,m-1){
			int e,k,nob;
			cin>>e>>k>>nob;
			e--;
			F1(j,0,nob-1){
				int b;
				cin>>b;
				b--;
				if(adj[e][b]<k)
					adj[e][b] = adj[b][e] = k;
			}
		}
		int s = (1<<(1<<n))-1;
		printf("Case #%d: %s\n", cnt++, find(dp,adj,s)?"YES":"NO");
	}
}