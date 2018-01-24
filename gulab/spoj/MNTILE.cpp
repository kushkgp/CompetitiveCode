#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w,h;
vector<vector<ll> > dp;

ll solve(int r, int idx, int mask, int nmask){	/* mask containes information about blocked indeces */
	if(r==h)
		return 1;
	if(!idx&&dp[r][mask]!=-1)
		return dp[r][mask];
	ll result = 0;
	int i;
	for (i = idx; i < w; ++i)
	{
		int f=1<<w-i-1;
		if(!(f&mask)){
			if(r<h-1){
				if(i==w-1)
					result+=solve(r+1,0,nmask|f,0);
				else
					result+=solve(r,i+1,mask|f,nmask|f);
			}
			if(i<w-1&&!((1<<(w-i-2))&mask)){
				int f2 = 1<<(w-i-2);
				if(i==w-2)
					result+=solve(r+1,0,nmask,0);
				else
					result+=solve(r,i+2,mask|f|f2,nmask);
			}
			break;
		}
	}
	if(i==w)
		result = solve(r+1,0,nmask,0);
	if(!idx)
		dp[r][mask] = result;
	return result;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>w>>h;
		if(w>h)
			swap(w,h);
		dp.resize(h,vector<ll>(1<<w,-1));
		cout<<solve(0,0,0,0)<<endl;
		dp.clear();
	}
}