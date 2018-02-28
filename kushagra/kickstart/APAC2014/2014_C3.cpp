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

int possible(int a, vi &pst){
	int ans = 0;
	while(a>0){
		if(!pst[a%10])
			return 0;
		ans++;
		a = a/10;
	}
	return ans;
}

int get_ans(int a,  vi &ans, vi &pst){
	if(ans[a]!= inf/2)
		return ans[a];
	int k;
	if(k = possible(a, pst))
		ans[a] = k;

	int r = sqrt(a);

	F1(i,2,r){
		if(a%i==0)
			ans[a] = min((ll)get_ans(i,ans,pst) + get_ans(a/i, ans, pst) + 1, (ll)ans[a]);
	}
	return ans[a];
}

int main(){
	int t,C=1;
	cin >> t;
	vi pst(10);
	while(t--){
		// cout << "st" << endl;
		F1(i,0,9){
			cin >> pst[i];
		}
		int x;
		cin >> x;
		// cout << x << endl;
		vi ans(x+1, inf/2);
		// F1(i,0,9){
		// 	ans[i] = pst[i]?1:inf/2;
		// }
		// cout << "yes" << endl;
		int out;
		out = get_ans(x,ans, pst) + 1;
		cout << "Case #" << C++ << ": ";
		if(out < inf/2)
			cout << out << endl;
		else
			cout << "Impossible" << endl;
		// cout << "again" << endl;
		// cout << t << "\n";
	}
}