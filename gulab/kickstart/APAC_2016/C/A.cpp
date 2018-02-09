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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int r,c,rs,cs,s;

inline bool check(const int & i, const int & j){
	return (i>=0)&&(i<r)&&(j>=0)&&(j<c);
}


double dfs(vector<vector<double> > v, int i, int j, int l, vvi & vis){
	double ans = pow(1-v[i][j],vis[i][j])*v[i][j];
	vis[i][j]++;
	if(l){
		double x = 0;
		if(check(i-1,j))
			x = max(x,dfs(v,i-1,j,l-1,vis));
		if(check(i+1,j))
			x = max(x,dfs(v,i+1,j,l-1,vis));
		if(check(i,j-1))
			x = max(x,dfs(v,i,j-1,l-1,vis));
		if(check(i,j+1))
			x = max(x,dfs(v,i,j+1,l-1,vis));
		ans+=x;
	}
	vis[i][j]--;
	return ans;
}

double util(vector<vector<double> > & v){
	double ans = 0;
	vvi vis(r,vi(c,0));
	if(s){
		if(check(rs-1,cs))
			ans = max(ans,dfs(v,rs-1,cs,s-1,vis));
		if(check(rs+1,cs))
			ans = max(ans,dfs(v,rs+1,cs,s-1,vis));
		if(check(rs,cs-1))
			ans = max(ans,dfs(v,rs,cs-1,s-1,vis));
		if(check(rs,cs+1))
			ans = max(ans,dfs(v,rs,cs+1,s-1,vis));
	}
	return ans;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>r>>c>>rs>>cs>>s;
		double p,q;
		cin>>p>>q;
		vector<vector<double> > v(r,vector<double>(c));
		F1(i,0,r-1)
			F1(j,0,c-1){
				char ch;
				cin>>ch;
				v[i][j] = ch=='A'?p:q;
			}
		printf("Case #%d: %.8lf\n", cnt++, util(v));
	}
}