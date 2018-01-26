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
/*
	location, length
*/

int main(){
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		int n;
		cin>>n;
		vvi v(n,vi(n));
		vpii d(n*n+1,mp(0,0));
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; ++j)
			{
				cin>>v[i][j];
				d[v[i][j]].ff = n*i+j;
			}
		}
		int ans = 0,room = 1;
		for(int i = n*n; i > 0; i--){
			d[i].ss++;
			if(ans<=d[i].ss){
				ans = d[i].ss;
				room = i;
			}
			int x = d[i].ff/n,y = d[i].ff%n;
			if(x && v[x-1][y]+1==v[x][y])
				d[v[x-1][y]].ss = max(d[v[x-1][y]].ss, d[i].ss);

			if(y && v[x][y-1]+1==v[x][y])
				d[v[x][y-1]].ss = max(d[v[x][y-1]].ss, d[i].ss);
			
			if(x < n-1 && v[x+1][y]+1==v[x][y])
				d[v[x+1][y]].ss = max(d[v[x+1][y]].ss, d[i].ss);
			
			if(y < n-1 && v[x][y+1]+1==v[x][y])
				d[v[x][y+1]].ss = max(d[v[x][y+1]].ss, d[i].ss);
		}
		printf("Case #%d: %d %d\n", cnt++, room, ans);
	}
}