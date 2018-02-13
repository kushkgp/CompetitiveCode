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

int hx[] = {2,2,-2,-2,1,1,-1,-1};
int hy[] = {1,-1,1,-1,2,-2,2,-2};
vv<char> chess(8,v<char>(8));

inline bool check(int x, int y){
	return (x>=0)&&(x<8)&&(y>=0)&&(y<8);
}


int simulate(pii pos){
	F1(i,0,7)
		if(check(pos.ff+hx[i],pos.ss+hy[i]) && chess[pos.ff+hx[i]][pos.ss+hy[i]]=='K')
			return 1;
	int x[] = {1,-1,0,0,1,1,-1,-1};
	int y[] = {0,0,1,-1,1,-1,1,-1};
	F1(k,0,7){
		F1(i,1,8){
			int X = pos.ff+x[k]*i, Y = pos.ss+y[k]*i;
			if(check(X,Y)){
				if(chess[X][Y]!='#'){
					if(chess[X][Y]=='Q'||chess[X][Y]==(k<4?'R':'B'))
						return 1;
					break;
				}
			}
			else
				break;
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		v<pii> self;
		pii kingpos;
		v<char> selftype;
		F1(i,0,7)
			F1(j,0,7){
				cin>>chess[i][j];
				if(chess[i][j] == 'k')
					kingpos = mp(i,j);
				else if(chess[i][j] - 'a' < 0 && chess[i][j]!='#')
					self.pb(mp(i,j)), selftype.pb(chess[i][j]);
			}

		int ans = 0;
		F1(j,0,7)
			if(chess[1][j] == 'P' && chess[0][j] == '#')
			{
				chess[1][j] = '#';
				chess[0][j]	= 'Q';
				ans+=simulate(kingpos);
				chess[0][j]	= 'R';
				ans+=simulate(kingpos);
				chess[0][j]	= 'B';
				ans+=simulate(kingpos);
				chess[0][j]	= 'K';
				ans+=simulate(kingpos);
				chess[0][j] = '#';
				chess[1][j] = 'P';
			}
		cout<<ans<<endl;
	}
}