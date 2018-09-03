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
	while (t--) {
		int n,a;
		cin >> n;
		vi even,odd;
		F1(i,0,n-1){
			cin >> a;
			if(i&1)
				odd.pb(a);
			else
				even.pb(a);
		}
		// cout << "okok" << endl;
		sort(all(odd));
		sort(all(even));
		vi final(n);
		F1(i,0,n-1){
			if(i&1)
				final[i] = odd[i>>1];
			else
				final[i] = even[i>>1];
		}
		int ans=-1;
		F1(i,0,n-2){
			if(final[i]>final[i+1]){
				ans=i;
				break;
			}
		}
		cout << "Case #" << C++ << ": " << (ans==-1?"OK":to_string(ans).c_str()) << endl;
	}	

	return 0;
}