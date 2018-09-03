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
		int n;
		cin >> n;
		vl wts(n,0);
		F1(i,0,n-1){
			cin >> wts[i];
		}
		reverse(all(wts));
		vl cap(n+1,-1);
		cap[0] = 1e15;

		F1(i,0,n-1){
			int st = n - (upper_bound(cap.rbegin(), cap.rend(), -1) - cap.rbegin()) + 1;
			// cout << st << endl;
			// return 0;
			F2(j,st,1){
				cap[j] = max(cap[j], min(6*wts[i], cap[j-1] - wts[i]));
				if(cap[j] > 6*wts[i])
					break;
			}
		}

		F2(i,n,0){
			if(cap[i]>=0){
				cout << "Case #" << C++ << ": " << i << endl;
				break;
			}
		}
	}

	return 0;
}