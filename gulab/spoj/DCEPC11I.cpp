/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

ll sum1(int a){			// sum1(a) = (1+2+3+....+a)%MOD
	ll x = ((ll)a)*(a+1);
	x>>=1;
	return x;
}

class SegTree3{
private:
	ll* tree;
	pill * d;
	int n;
	int h;
	void apply_val(int p, pill value, int k){
		int t = value.ff;
		tree[p] += t*(sum1(1<<k));
		tree[p] += value.ss*(1<<k);
	}
	void calc(int p, int k) {
		tree[p] = tree[p<<1] + tree[p<<1|1];
		if(d[p].ff) apply_val(p,d[p],k);
	}
	void apply(int p, pill value, int k) {
		apply_val(p,value,k);
		if (p < n) d[p].ff+=value.ff, d[p].ss+=value.ss;
	}
public:
	void build(int l, int r) {
		int k = 1;
		for (l += n, r += n; l > 1; k++) {
			l >>= 1, r >>= 1;
			for (int i = r; i >= l; --i) calc(i, k);
		}
	}
	void push(int l, int r) {
		int s = h, k = (h-1);
		for (l += n, r += n; s > 0; --s, k--)
			for (int i = l >> s; i <= r >> s; ++i) if (d[i].ff != 0) {
				apply(i<<1, d[i], k);
				d[i].ss += d[i].ff*(1<<k);
				apply(i<<1|1, d[i], k);
				d[i].ff = d[i].ss = 0;
			}
	}
	void range_update(int l, int r) {
		push(l, l);
		push(r, r);
		pii lval,rval;
		lval.ff = rval.ff = 1;
		lval.ss = 0;
		rval.ss = r-l;
		int l0 = l, r0 = r, k = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k++) {
			if (l&1) apply(l++, lval, k), lval.ss+=(1<<k);
			if (!(r&1)) apply(r--, rval, k),rval.ss-=(1<<(k+1));
			else rval.ss-=(1<<k);
		}
		build(l0, l0);
		build(r0, r0);
	}
	ll range_query(int l, int r) {
		push(l, l);
		push(r, r);
		ll res = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = res + tree[l++];
			if (!(r&1)) res = res + tree[r--];
		}
		return res;
	}
	SegTree3(int size):n(size){
		tree = new ll[n<<1];
		d = new pill[n];
		memset(tree,0,sizeof(ll)*(n<<1));
		memset(d,0,sizeof(pill)*(n));
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	~SegTree3(){
		delete[] tree;
		delete[] d;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	SegTree3 T(n);
	while(q--){
		int f,l,r;
		cin>>f>>l>>r;
		if(f)
			cout<<T.range_query(--l,--r)<<endl;
		else
			T.range_update(--l,--r);
	}
}