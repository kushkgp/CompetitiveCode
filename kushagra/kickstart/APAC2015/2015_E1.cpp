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


int get_ans(string inp){
	int ans = 1;
	int n = inp.size();
	if(n>1 && inp[0]!=inp[1])
		ans*=2;
	F1(i,1,n-2){
		int mult = 1;
		if(inp[i-1]!=inp[i])
			mult++;
		if(inp[i+1]!=inp[i] && inp[i-1]!=inp[i+1])
			mult++;
		ans = ((ll)ans*mult)%mod;
	}
	if(n>1 && inp[n-1]!=inp[n-2])
		ans = ((ll)ans*2)%mod;
	return ans;
}

int main(){
	int t,C=1;
	cin >> t;
	// cout << endl;
	while(t--){
		string ans;
		cin >> ans;
		cout << "Case #" << C++ << ": " << get_ans(ans) << endl;
	}
}