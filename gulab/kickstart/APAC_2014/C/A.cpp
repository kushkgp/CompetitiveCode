/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void preprocess(vvi & m, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(m[i][j]!=-1){
				for(int k1 = -1; k1 < 2; k1++)
					for(int k2 = -1; k2 < 2; k2++)
						if(i+k1>=0 && j+k2>=0 && i+k1<n && j+k2<n)
							m[i][j]+=m[i+k1][j+k2]==-1?1:0;
			}
		}
	}
}

void dfs(vvi & m, vvi & vis, int n, int i, int j){
	vis[i][j] = 1;
	if(m[i][j])
		return;
	for(int k1 = -1; k1 < 2; k1++)
		for(int k2 = -1; k2 < 2; k2++)
			if(i+k1>=0 && j+k2>=0 && i+k1<n && j+k2<n)
				if(!vis[i+k1][j+k2])
					dfs(m,vis,n,i+k1,j+k2);
}

int main(){
	int t;
	cin>>t;
	int cnt = 1;
	while(t--){
		int n;
		cin>>n;
		vvi m(n,vi(n));
		vvi vis(n,vi(n,0));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				char c;
				cin>>c;
				m[i][j] = c=='*'?-1:0;
			}
		}
		preprocess(m,n);
		int ans = 0;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++){
				if(m[i][j]!=-1 && !vis[i][j] && !m[i][j])
					ans++,dfs(m,vis,n,i,j);
			}
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++){
				if(m[i][j]!=-1 && !vis[i][j])
					ans++;
			}
		printf("Case #%d: %d\n",cnt++, ans);
	}
}