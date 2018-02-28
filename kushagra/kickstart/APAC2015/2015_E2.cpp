/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t,C=1;
	cin >> t;
	// cout << endl;
	while(t--){
		int n , k;
		cin >> n >> k;

		vector<map<int, int> > mymap(2);

		vvi input(4,vi(n));

		F1(i,0,3){
			F1(j,0,n-1){
				cin >> input[i][j];
			}	
		}

		F1(k,0,1){
			F1(i,0,n-1){
				F1(j,0,n-1){
					mymap[k][ input[2*k][i] ^ input[2*k+1][j] ]++;
				}
			}
		}

		ll answer = 0;
		for(auto it = mymap[0].begin();it!=mymap[0].end();it++){
			if(mymap[1].find((it->ff)^k)!=mymap[1].end())
				answer += (ll)it->ss * mymap[1][(it->ff)^k];
		}
		cout << "Case #" << C++ <<": " << answer << endl;
		
	}
}