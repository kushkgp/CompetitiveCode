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
typedef pair< pii, pii > ppii;
typedef vector<pii> vpii;

int cnt[1000001];
int ans = 0;

//op == 0->++, else --
void add(int i, int op){
	cnt[i] += op?-1:1;
	if(cnt[i] == 1 && !op)
		ans++;
	else if(cnt[i] == 0 && op)
		ans--;
}

int main(){
	memset( cnt, 0, sizeof(cnt) );
	int n,q;
	BOOST;
	cin>>n;
	vi a(n);
	int sqrt_n	= sqrt(n);
	F1(i, 0, n-1)
		cin>>a[i];
	cin>>q;
	v<ppii> b(q, mp( mp(0, 0), mp(0, 0) ) );
	F1(i, 0, q-1){
		cin>>b[i].ff.ff>>b[i].ff.ss;
		b[i].ss.ss = i;
	}
	//	a and b are different from current scope definition
	auto less_than	= [&] ( ppii & a, ppii & b ) -> bool
	{
		if( a.ff.ff / sqrt_n == b.ff.ff / sqrt_n )
			return a.ff.ss < b.ff.ss;
		else
			return a.ff.ff / sqrt_n < b.ff.ff / sqrt_n;
	};
	sort( all(b), less_than );

	int lt = 0, rt = -1;
	F1(j, 0, q-1){
		int l = b[j].ff.ff-1;
		int r = b[j].ff.ss-1;
		// cout<<l<<"--"<<r<<endl;
		F1(i, lt, l-1)
			add(a[i], 1);
		F2(i, lt-1, l)
			add(a[i], 0);
		// cout<<ans<<endl;
		F1(i, rt+1, r)
			add(a[i], 0);
		F2(i, rt, r+1)
			add(a[i], 1);
		// cout<<ans<<endl;
		b[j].ss.ff = ans;
		lt = l, rt = r;
	}
	//	a and b are different from current scope definition
	auto less_than2	= [&] ( ppii & a, ppii & b ) -> bool
	{
		return a.ss.ss < b.ss.ss;
	};
	sort( all(b), less_than2 );
	F1( i, 0, q-1 )
		cout<<b[i].ss.ff<<"\n";
}