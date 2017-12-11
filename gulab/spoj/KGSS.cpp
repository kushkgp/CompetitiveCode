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

class SegTree{
private:
	vpii tree;					
	int n;
	pii calc(const pii& a, const pii& b){
		pii ret;
		ret.ff = max(a.ff,b.ff);
		ret.ss = min(a.ff,b.ff);
		ret.ss = max3(ret.ss,a.ss,b.ss);
		return ret;
	}						
public:
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i]=calc(tree[i<<1],tree[i<<1|1]);
	}
	void point_modify(int p, int value) {	
		for (tree[p+= n].ff = value; p > 1; p >>= 1) tree[p>>1]=calc(tree[p],tree[p^1]);	/* p^1 gives sibling*/
	}
	int range_query(int l, int r) {
		pii res;
		res.ff = res.ss = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = calc(res,tree[l++]);										/* if l is odd then apply func */
			if (!(r&1)) res = calc(res,tree[r--]);									/* if r is even then apply func */
		}
		return res.ff+res.ss;
	}
	SegTree(const vi & v,int size):n(size){
		tree.resize(n<<1);
		for (int i = 0; i < n; ++i)
			tree[i+n] = mp(v[i],0);
		build();
	}
};

int main(){
	BOOST;
	int n;
	cin>>n;
	vi v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	SegTree T(v,n);
	int q;
	cin>>q;
	while(q--){
		char c;
		int a,b;
		cin>>c>>a>>b;
		if(c=='U')
			T.point_modify(--a,b);
		else
			cout<<T.range_query(--a,--b)<<endl;
	}
	return 0;
}
