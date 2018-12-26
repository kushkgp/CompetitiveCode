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
typedef bitset<5000> bt;
typedef pair<pii, pair<int, bt> > pab;
int cnt[5000];
bitset<5000> ans;

//op == 0->++, else --
void add(int i, int op){
	cnt[i] += op?-1:1;
	if(cnt[i] == 1 && !op)
		ans[i] = 1;
	else if(cnt[i] == 0 && op)
		ans[i] = 0;
}

int main(){
	memset( cnt, 0, sizeof(cnt) );
	int n,q;
	BOOST;
	cin>>n;
	v<int> a(n), b(n);
	int sqrt_n	= sqrt(n);
	F1(i, 0, n-1)
		cin>>a[i];
	F1(i, 0, n-1){
	    cin>>b[i];
	    a[i]--, b[i]--;
	}
	cin>>q;
	v<pab> qa(q), qb(q);
	F1(i, 0, q-1){
		cin>>qa[i].ff.ff>>qa[i].ff.ss;
		cin>>qb[i].ff.ff>>qb[i].ff.ss;
		qa[i].ss.ff = qb[i].ss.ff = i;
	}
	//	a and b are different from current scope definition
	auto less_than	= [&] ( pab & a, pab & b ) -> bool
	{
		if( a.ff.ff / sqrt_n == b.ff.ff / sqrt_n )
			return a.ff.ss < b.ff.ss;
		else
			return a.ff.ff / sqrt_n < b.ff.ff / sqrt_n;
	};
	auto fill_ans = [&](v<pab> & q, v<int> & a){
	    ans.reset();
	    memset(cnt, 0, sizeof(cnt));
	    sort(all(q), less_than);
	    int lt = 0, rt = -1;
    	F1(j, 0, q.size()-1){
    		int l = q[j].ff.ff-1;
    		int r = q[j].ff.ss-1;
    		F1(i, lt, l-1)
    			add(a[i], 1);
    		F2(i, lt-1, l)
    			add(a[i], 0);
    		F1(i, rt+1, r)
    			add(a[i], 0);
    		F2(i, rt, r+1)
    			add(a[i], 1);
    		q[j].ss.ss = ans;
    		lt = l, rt = r;
    	}
    	sort( all(q), [] ( pab & a, pab & b ) -> bool
    	{return a.ss.ff < b.ss.ff;} );
	};

	fill_ans(qa, a);
	fill_ans(qb, b);
	
	F1( i, 0, q-1 )
		cout<<(qa[i].ss.ss|qb[i].ss.ss).count()<<"\n";
}