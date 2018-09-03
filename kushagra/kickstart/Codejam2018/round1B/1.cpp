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
		int n,l;
		cin >> n >> l;

		vi l_res(n,0);
		int cnt=0;
		int perc = 0;

		F1(i,0,l-1){
			int k;
			cin >> k;
			cnt += k;

			k*=100;

			perc += k/n;

			k=k%n;
			l_res[i]=k;
			// cout << k << " ";
		}
		if(100%n==0){
			cout << 100 << endl;
			continue;
		}

		asort(l_res);

		int left = n - cnt;
		F2(i,n-1,0){
			// cout << i << " " << perc << " " << l_res[i] << endl ;
			if(l_res[i]>(n-1)/2){
				perc += 1;
				continue;
			}
			if(100*left+l_res[i]<=(n-1)/2)
				break;
			int chg = ceil((1.0*((n+1)/2 - l_res[i]))/(100%n));
			if(chg>left){
				perc += (left*100)/n;
				break;
			}
			cout << chg << endl;
			perc += (chg*100)/n;
			perc += 1;
			left -= chg;
		}

		cout << perc << endl;
	}	

	return 0;
}