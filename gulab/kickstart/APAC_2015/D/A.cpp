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

void dfs(vvi & m, vvi & vis, int & r, int & c, int x, int y){
	vis[x][y]=1;
	if(x-1>=0 && m[x-1][y] && !vis[x-1][y])
		dfs(m,vis,r,c,x-1,y);

	if(y-1>=0 && m[x][y-1] && !vis[x][y-1])
		dfs(m,vis,r,c,x,y-1);

	if(x+1<r && m[x+1][y] && !vis[x+1][y])
		dfs(m,vis,r,c,x+1,y);

	if(y+1<c && m[x][y+1] && !vis[x][y+1])
		dfs(m,vis,r,c,x,y+1);
}

int main(){
	int t,cnt=1;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		vvi m(r,vi(c));
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				char ch;
				cin>>ch;
				m[i][j] = (ch=='1');
			}
		}
		int ans = 0;
		{
			vvi vis(r,vi(c,0));
			for (int i = 0; i < r; ++i){
				for (int j = 0; j < c; ++j){
					if(m[i][j] && !vis[i][j]){
						ans++;
						dfs(m,vis,r,c,i,j);
					}
				}
			}
		}
		int n;
		cin>>n;
		printf("Case #%d:\n", cnt++);
		while(n--){
			char ch;
			cin>>ch;
			if(ch=='Q')
				cout<<ans<<endl;
			else{
				int x,y,z;
				cin>>x>>y>>z;
				if(m[x][y]!=z){
					vvi vis(r,vi(c,0));
					m[x][y] = 0;
					int curr=0;
					if(x-1>=0 && m[x-1][y] && !vis[x-1][y]){
						curr++;
						dfs(m,vis,r,c,x-1,y);
					}
					if(y-1>=0 && m[x][y-1] && !vis[x][y-1]){
						curr++;
						dfs(m,vis,r,c,x,y-1);
					}					
					if(x+1<r && m[x+1][y] && !vis[x+1][y]){
						curr++;
						dfs(m,vis,r,c,x+1,y);
					}
					if(y+1<c && m[x][y+1] && !vis[x][y+1]){
						curr++;
						dfs(m,vis,r,c,x,y+1);
					}
					if(z)
						ans-=curr-1;
					else
						ans+=curr-1;
					m[x][y] = z;
				}
			}
		}
	}
}