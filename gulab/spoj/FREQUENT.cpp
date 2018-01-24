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

typedef struct node{
	pii l,r,x;
	node(){
		l.ss = 0;
		r.ss = 0;
		x.ss = 0;
	}
}node;

class SegTree{
private:
	node* tree;					/* tree pointer */
	int n;						/* size of array which is used to build the segment tree */
	node calc(const node& a, const node &b){
		node t;
		t.l = a.l;
		t.r = b.r;
		//
		if(a.l.ff==b.l.ff)
			t.l.ss+=b.l.ss;
		if(b.r.ff==a.r.ff)
			t.r.ss+=a.r.ss;
		//
		if(a.l.ss == 0)
			t.l = b.l;
		if(b.r.ss == 0)
			t.r = a.r;
		// same element
		if(a.x.ff==b.x.ff){
			t.x.ff = a.x.ff;
			t.x.ss = a.x.ss+b.x.ss;
			return t;
		}
		// a.r and b.l >= both elements
		if(a.r.ff==b.l.ff&&a.r.ss+b.l.ss>=max(a.x.ss,b.x.ss)){
			t.x = a.r;
			t.x.ss+=b.l.ss;
			return t;
		}
		// a.x or b.x
		if(a.x.ss>b.x.ss)
			t.x = a.x;
		else
			t.x = b.x;
		return t;
	}
public:
	node* get_Array(){
		return tree + n;
	}
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i] = calc(tree[i<<1],tree[i<<1|1]);
	}

	int range_query(int l, int r) {
		node resl,resr;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) resl = calc(resl,tree[l++]);										/* if l is odd then apply func */
			if (!(r&1)) resr = calc(tree[r--],resr);									/* if r is even then apply func */
		}
		resl = calc(resl,resr);
		return resl.x.ss;
	}
	SegTree(int size):n(size){
		tree = new node[n<<1];
		memset(tree,0,sizeof(node)*(n<<1));
	}
	~SegTree(){
		delete[] tree;
	}
};


int main(){
	int n,q;
	cin>>n;
	while(n){
		cin>>q;
		SegTree T(n);
		node* a = T.get_Array();
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].x.ff;
			a[i].l.ff = a[i].r.ff = a[i].x.ff;
			a[i].l.ss = a[i].r.ss = a[i].x.ss = 1;
		}
		T.build();
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<T.range_query(--l,--r)<<endl;
		}
		cin>>n;
	}
	return 0;	
}