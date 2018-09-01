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


int main(){
	// BOOST;
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vpii v(n);
		vpii dp1(n);
		vpii dp2(n);
		F1(i,0,n-1){
			int d, a, b;
			cin>>d>>a>>b;
			v[i].ff = d+a;
			v[i].ss = d-b;
		}
		dp1[0] = mp(1,-1);
		dp2[0] = mp(1,-1);
		pii m = mp(1,1);
		F1(i, 1, n-1){
			pii ans1;
			{
				pii ans = mp(1,-1);
				if(v[i].ff == v[i-1].ff)
					ans = mp(dp1[i-1].ff+1, dp1[i-1].ss);
				else{
					if(dp2[i-1].ss==-1){
						ans = mp(dp2[i-1].ff+1, i-1);
					}
					else{
						if(v[i].ff == v[dp2[i-1].ss].ff){
							ans = mp(dp2[i-1].ff+1, i-1);
						}
						else{
							ans = mp(i-dp2[i-1].ss, i-1);
						}
					}
				}
				dp1[i] = ans;
				ans1 = ans;
			}

			{
				pii ans = mp(1,-1);
				if(v[i].ss == v[i-1].ss)
					ans = mp(dp2[i-1].ff+1, dp2[i-1].ss);
				else{
					if(dp1[i-1].ss==-1){
						ans = mp(dp1[i-1].ff+1, i-1);
					}
					else{
						if(v[i].ss == v[dp1[i-1].ss].ss){
							ans = mp(dp1[i-1].ff+1, i-1);
						}
						else{
							ans = mp(i-dp1[i-1].ss, i-1);
						}
					}
				}
				dp2[i] = ans;
				if(m.ff<max(ans1.ff,ans.ff))
					m = mp(max(ans1.ff,ans.ff),1);
				else if(m.ff == max(ans1.ff,ans.ff)){
					m.ss++;
				}
			}
		}
		printf("Case #%d: %d %d", cnt++, m.ff, m.ss);
	}
}