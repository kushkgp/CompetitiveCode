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

typedef struct sum{
	int lsum,rsum,xsum,tsum;
	void operator=(const int& b){
		this->lsum = this->rsum = this->xsum = this->tsum = b;
	}
	sum(int x=0){
		(*this).operator=(x);
	}
}sum;

sum operator+(const sum& a,const sum& b){
	sum temp;
	temp.lsum = max(a.lsum,a.tsum+b.lsum);
	temp.rsum = max(b.rsum,b.tsum+a.rsum);
	temp.tsum = a.tsum+b.tsum;
	temp.xsum = max(max3(a.rsum+b.lsum,a.xsum,b.xsum),temp.tsum);
	return temp;
}

template <typename T>
class SegTree2{
private:
	T* tree;
	int n;
	void build(int p) {
		while (p > 1) p >>= 1, tree[p] = tree[p<<1]+tree[p<<1|1];
	}
public:
	T* get_Array(){
		return tree + n;
	}
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1]+tree[i<<1|1];
	}
	int range_query(int l, int r) {
		l+=n;r+=n;
		T resl(-10001),resr(-10001);
		resl.tsum = resr.tsum = 0;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l&1) resl = resl+tree[l++];					/* if l is odd then apply func */
			if (!(r&1)) resr = tree[r--]+resr;				/* if r is even then apply func */
		}
		return (resl+resr).xsum;
	}
	void point_modify(int p, int x){
		p+=n;
		tree[p]=x;
		build(p);
	}
	SegTree2<T>(int size):n(size){
		tree = new T[n<<1];
	}
	~SegTree2<T>(){
		delete[] tree;
	}
};

int main(){
	BOOST;
	int n,q;
	cin>>n;
	SegTree2<sum> T(n);
	sum *a = T.get_Array();
	for (int i = 0; i < n; ++i){
		int temp;
		cin>>temp;
		a[i] = temp;
	}
	T.build();
	cin>>q;
	for(int i = 0; i < q; i++){
		int f,l,r;
		cin>>f>>l>>r;
		if(f)
			cout<<T.range_query(--l,--r)<<endl;
		else
			T.point_modify(--l,r);
	}
	return 0;
}