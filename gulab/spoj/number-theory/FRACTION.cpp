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
typedef v<pii> vpii;
/* Farey sequence */


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vpii q(m);
		F1(i,0,m-1){
			q[i].ss=i;
			cin>>q[i].ff;
		}
		sort(all(q));
		vpii ans(m);
		int x1 = 0, x2 = 1, y1 = 1, y2 = n, x, y;
		int cnt = 2;
		F1(i,0,m-1){
			if(q[i].ff>2){
				while(cnt<q[i].ff){
					x = ((y1+n)/y2)*x2-x1;
					y = ((y1+n)/y2)*y2-y1;
					x1 = x2, y1 = y2;
					x2 = x, y2 = y;
					cnt++;
				}
				ans[q[i].ss].ff = x, ans[q[i].ss].ss = y;
			}
			else if(q[i].ff==1)
				ans[q[i].ss].ff = x1, ans[q[i].ss].ss = y1;
			else
				ans[q[i].ss].ff = x2, ans[q[i].ss].ss = y2;
		}
		F1(i,0,m-1)
			cout<<ans[i].ff<<"/"<<ans[i].ss<<endl;
	}
}