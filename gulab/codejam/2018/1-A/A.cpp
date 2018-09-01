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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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
typedef vector<pii> vpii;

void printv(vi & a){
	F1(i, 0, a.size()-1)
		cout<<a[i]<<" ";
	cout<<endl;
}

bool check(vi &cut, vi & a, int cutsum, int totcut){
	int x= 0;
	int tot = 0;
	F1(i,0,a.size()-1){
		x+=a[i];
		if(x>cutsum)
			return false;
		if(x==cutsum){
			x = 0;
			cut.pb(i);
			tot++;
		}
	}
	return tot==totcut;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int r, c, h, v;
		cin>>r>>c>>h>>v;
		vvi m(r, vi(c, 0));
		int sum = 0;
		F1(i,0,r-1)
			F1(j,0,c-1){
				char c;
				cin>>c;
				if(c=='@')
					m[i][j] = 1;
				sum+=m[i][j];
			}
		vi vt(c,0), hz(r,0);
		F1(i, 0, r-1)
			F1(j, 0, c-1){
				hz[i]+=m[i][j];
			}
		F1(j, 0, c-1)
			F1(i, 0, r-1){
				vt[j]+=m[i][j];
			}
		vi vcuts, hcuts;
		printf("Case #%d: ", cnt++);
		if(check(vcuts, vt, sum/(v+1), v+1)&&check(hcuts, hz, sum/(h+1), h+1)){
			int f = 1;
			// cout<<"hi"<<endl;
			// printv(vcuts);
			int cutsum = sum/((v+1)*(h+1));
			int lasth = 0;
			F1(i,0,h && f){
				int lastv = 0;
				F1(j,0,v && f){
					int temp = 0;
					// cout<<"f"<<vt[j]<<endl;
					F1(k,lasth,hcuts[i]){
						F1(l,lastv,vcuts[j]){
							temp+=m[k][l];
						}
					}
					if(temp!=cutsum){
						f = 0;
						// cout<<temp<<endl;
						// F1(k,lasth,hcuts[i]){
						// 	F1(l,lastv,vcuts[j]){
						// 		cout<<k<<" "<<l<<endl;
						// 		// temp+=m[l][k];
						// 	}
						// }
					}
					lastv = vcuts[j]+1;
					// cout<<"asdaf"<<lastv<<endl;
				}
				lasth = hcuts[i]+1;
			}
			if(!f)
				printf("IM");
		}
		else if(sum){
			printf("IM");
		}
		printf("POSSIBLE\n");
	}
}