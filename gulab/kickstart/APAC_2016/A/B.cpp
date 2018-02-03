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
int r,c;

inline bool check(int x, int y){
	return (x>=0)&&(x<r)&&(y>=0)&&(y<c);
}

void dfs(int x, int y, vvi & h, vvi & vis, int & curr){
	vis[x][y] = 1;
	F1(i,-1,1)
		if(check(x+i,y)){
			if(!vis[x+i][y] && h[x][y] == h[x+i][y])
				dfs(x+i,y,h,vis,curr);
			else if(h[x][y] != h[x+i][y])
					curr=min(max(0,h[x+i][y]-h[x][y]),curr);
		}
		else
			curr = 0;

	F1(i,-1,1)
		if(check(x,y+i)){
			if(!vis[x][y+i] && h[x][y] == h[x][y+i])
				dfs(x,y+i,h,vis,curr);
			else if(h[x][y] != h[x][y+i])
					curr=min(max(0,h[x][y+i]-h[x][y]),curr);
		}
		else
			curr = 0;
}


void dfs2(int x, int y, vvi & h, vvi & vis, int & curr, int & ans){
	ans+=curr;
	vis[x][y] = 2;
	h[x][y]+=curr;
	F1(i,-1,1)
		if(check(x+i,y) && vis[x+i][y]==1)
			dfs2(x+i,y,h,vis,curr,ans);
	F1(i,-1,1)
		if(check(x,y+i) && vis[x][y+i]==1)
			dfs2(x,y+i,h,vis,curr,ans);
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>r>>c;
		vvi h(r,vi(c));
		int mi=1000,ma=1;
		F1(i,0,r-1)
			F1(j,0,c-1){
				cin>>h[i][j];
				mi = min(mi,h[i][j]);
				ma = max(ma,h[i][j]);
			}
		int ans = 0;
		F1(k,mi,ma){
			vvi vis(r,vi(c,0));
			F1(i,0,r-1)
				F1(j,0,c-1)
					if(k == h[i][j] && !vis[i][j]){
						int x = 1000;
						dfs(i,j,h,vis,x);
						dfs2(i,j,h,vis,x,ans);
					}
		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
}