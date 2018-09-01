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
	BOOST;
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi b, c, a(n);
		F1(i, 0, n-1){
			int x;
			cin>>x;
			if(i%2)
				c.pb(x);
			else
				b.pb(x);
		}
		sort(all(b));
		sort(all(c));
		F1(i, 0, n-1){
			if(i%2)
				a[i] = c[i/2];
			else
				a[i] = b[i/2];
		}
		int ans = -1;
		F1(i, 0, n-2){
			if(a[i]>a[i+1]){
				ans = i;
				break;
			}
		}
		printf("Case #%d: %s\n", cnt++, ans==-1?"OK":to_string(ans).c_str());
	}
}