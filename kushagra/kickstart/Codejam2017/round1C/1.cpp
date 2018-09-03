/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define min3(a,b,c) (min(min(a,b),c))
#define max3(a,b,c) (max(max(a,b),c))
#define mod 1000000007
#define inf INT_MAX

#define F2(x,y,z) for(int x = y; x >= z; x--)
#define F1(x,y,z) for(int x = y; x <= z; x++)
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define ss second
#define ff first
#define mp make_pair
#define pb push_back

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;

int main(){
	int C = 1;
	int t; cin >> t;
	long double pie = 3.1415926535897932384626433832795028;
	cout << setprecision(20);
	while (t--) {
		int n,k;
		cin >> n >> k;
		vector<pair<ll,int> > area(n,mp(0,0));
		vi rank_area(n,-1);
		vpii rad(n,mp(0,0));
		vi ht(n,0);
		ll r,h;
		F1(i,0,n-1){
			cin >> r >> h;
			area[i] = mp(r*h,i);
			rad[i] = mp(r,i);
			ht[i] = h;
		}
		dsort(area);
		dsort(rad);
		F1(i,0,n-1){
			rank_area[area[i].ss] = i;
		}
		F1(i,1,n-1){
			area[i].ff += area[i-1].ff;
		}
		ll area_max = -1;

		ll area_k = area[k-1].ff;
		ll area_kd = k>1?area[k-2].ff:0;
		area_k = 2*area_k;
		area_kd = 2*area_kd;
		
		F1(i,0,n-1){
			if(rank_area[rad[i].ss] < k){
				area_max = max((ll)area_max,  rad[i].ff * rad[i].ff + area_k);
			}
			else{
				area_max = max((ll)area_max, 2*rad[i].ff*ht[rad[i].ss] + rad[i].ff * rad[i].ff + area_kd);	
			}
		}
		cout <<"Case #" << C++ << ": " << M_PI * (long double)area_max << endl;

	}	

	return 0;
}