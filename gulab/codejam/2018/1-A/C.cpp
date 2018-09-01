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
typedef vector<pii> vpii;

int main(){
	int cnt = 1, t;
	cin>>t;
	while(t--){
		int n;
		long double p;
		cin>>n>>p;
		long double ans = 0;
		long double x = 0;
		while(n--){
			long double a,b;
			cin>>a>>b;
			ans+=(a+b)*2;
			x+=sqrt(a*a+b*b)*2;
			minx = min(a,b);
		}
		printf("Case #%d: ", cnt++);
		if(ans+x>p)
			ans = p;
		else
			ans +=x;
		printf("%.10LF\n", ans);

	}
}