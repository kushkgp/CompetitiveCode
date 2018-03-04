/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007
#define MOD 1000000007

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
typedef vector<pii> vii;
typedef vector<vii> vvii;


void compute(int n, int maxi, vi &num, vi &den){
	num.pb(0),den.pb(1);
	num.pb(1),den.pb(n);
	int i=2;
	while(maxi>=i){
		int k = (n+den[i-2])/den[i-1];
		num.pb(k*num[i-1] - num[i-2]);
		den.pb(k*den[i-1] - den[i-2]);
		i++;
	}
	return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vi qr(m);
		int maxi = 0;
		F1(i,0,m-1){
			cin >> qr[i];
			maxi = max(maxi, qr[i]);
		}
		vi a,b;
		compute(n,maxi,a,b);
		F1(i,0,m-1){
			maxi = max(maxi, qr[i]);
			cout << a[qr[i]-1] << "/" << b[qr[i]-1] << endl ;
		}
	}
}