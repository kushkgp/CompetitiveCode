#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTree4{
private:
	T* tree;					/* tree pointer */
	T* d;						/* array used for lazy propagation */
	int n;						/* size of array which is used to build the segment tree */
	int h;						/* index of left most set bit */

	/* Helper function in build */
	void calc(int p, int k) {
		tree[p] = tree[p<<1] + tree[p<<1|1];				/* Add children */
		if(d[p]) tree[p] = d[p] * k;						/* Restore affect of d[p] as this d[p] doesn't affected children yet */
	}
	/* add value*k to p */
	void apply(int p, T value, int k) {	
		tree[p] = value*k;									/* change value of node with value*k */
		if (p < n) d[p] = value;							/* Change value of d[p] */
	}
	
public:
	/* get array to directly update in the array */
	/* note : there should be push(l,r) before and build(l,r) after all the modifications */
	T* get_Array(){
		return tree + n;
	}
	T* get_d(){
		return d;
	}
	/* Build tree from children in [l,r] */
	void build(int l, int r) {
		int k = 2;
		for (l += n, r += n; l > 1; k <<= 1) {
			l >>= 1, r >>= 1;
			for (int i = r; i >= l; --i) calc(i, k);
		}
	}
	/* Push values down in the range [l,r] */
	void push(int l, int r) {
		int s = h, k = 1 << (h-1);
		for (l += n, r += n; s > 0; --s, k >>= 1)
			for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
				apply(i<<1, d[i], k);
				apply(i<<1|1, d[i], k);
				d[i] = 0;
			}
	}
	/* modifies all the values by value */
	void range_modify(int l, int r, T value) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		int l0 = l, r0 = r, k = 1;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k <<= 1) {
			if (l&1) apply(l++, value, k);
			if (!(r&1)) apply(r--, value, k);
			// if(value == 1) cout<<d[5]<<endl;
		}
		build(l0, l0);													/* building along r to root */
		build(r0, r0);													/* building along r to root */
	}
	/* Range Queries from l to r including both l and r */
	T range_query(int l, int r) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		T res = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = res + tree[l++];								/* if l is odd then apply func */
			if (!(r&1)) res = res + tree[r--];							/* if r is even then apply func */
		}
		return res;
	}
	/* Constructor which copies from array, complexity - n */
	/* Here n denotes size of passed array */
	SegTree4<T>(T * a, int size):n(size){
		tree = new T[n<<1];
		d = new T[n];
		for (int i = 0; i < n; ++i)	tree[i+n] = a[i];
		memset(d,0,sizeof(T)*(n));
		this->build(0,n-1);
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	SegTree4<T>(int size):n(size){
		tree = new T[n<<1];
		d = new T[n];
		memset(d,0,sizeof(T)*(n));
		memset(tree,0,sizeof(T)*(n<<1));
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	/* Deconstructor */
	~SegTree4<T>(){
		delete[] tree;
		delete[] d;
	}
};

/*

*/

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		SegTree4<int> b(1e7);
		int m = 0;
		int mi = INT_MAX;
		for (int i = 1; i <= n; ++i)
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			m = max(m,r);
			mi = min(mi,l);
			b.range_modify(l,r,i);
		}
		// 		cout<<"hi"<<endl;
		b.push(mi,m);
		int *c = b.get_Array();
		set<int> s;
		for (int i = mi; i <= m; ++i)
		{
			int x = c[i];
			if(!x) continue;
			if(s.find(x)==s.end())
				s.insert(x);
			// cout<<c[i]<<" ";
		}
		// cout<<endl;
		cout<<s.size()<<endl;
	}
}