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
		int n,m,q;
		cin >> n >> m >> q;
		vi wind(m);
		F1(i,0,m-1){
			cin >> wind[i];
		}

		vi nr_pos(m), nr_neg(m);

		int last_pos = -1;
		int last_neg = -1;
		F1(i,0,m-1){
			if(wind[i]>0){
				last_pos = i;
			}
			if(wind[i]<0)
				last_neg = i;
			nr_pos[i] = last_pos;
			nr_neg[i] = last_neg;
		}
		last_pos = m;
		last_neg = m;
		F2(i, m-1, 0){
			if(wind[i] > 0){
				last_pos = i;
			}
			if(wind[i] < 0){
				last_neg = i;
			}
			if(abs(last_pos - i) < abs(nr_pos[i] - i))
				nr_pos[i] = last_pos;
			if(abs(last_neg - i) < abs(nr_neg[i] - i))
				nr_neg[i] = last_neg;
			if(nr_neg[i]<0 || nr_neg[i]>=m)
				nr_neg[i] = inf;
			if(nr_pos[i]<0 || nr_pos[i]>=m)
				nr_pos[i] = inf;
		}
		int required = 0;
		F1(i,0,n-1){
			int x,y;
			cin >> x >> y;
			if(x < 0){
				required += abs(nr_pos[y] - y);
			}
			if(x>0)
				required += abs(nr_neg[y] - y);
		}
		cout << endl << required << endl;

	}
}