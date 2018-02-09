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

ll m[3000][3000];

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int r,c,k;
		cin>>r>>c>>k;
		F1(i,0,r-1)
			F1(j,0,c-1)
				m[i][j] = 1;
		F1(i,0,k-1){
			int x,y;
			cin>>x>>y;
			m[x][y] = 0;
		}
		F1(i,0,r-1)
			F1(j,0,c-1)
				if(m[i][j]&&(i||j)){
					m[i][j] = inf;
					m[i][j] = i?min(m[i][j],m[i-1][j]+1):1;
					m[i][j] = j?min(m[i][j],m[i][j-1]+1):1;
					m[i][j] = i&&j?min(m[i][j],m[i-1][j-1]+1):1;
				}
		
		F1(i,0,r-1)
			F1(j,0,c-1){
				m[i][j]+=i?m[i-1][j]:0;
				m[i][j]+=j?m[i][j-1]:0;
				m[i][j]-=i&&j?m[i-1][j-1]:0;
			}
		printf("Case #%d: %lld\n", cnt++, m[r-1][c-1]);
	}
}