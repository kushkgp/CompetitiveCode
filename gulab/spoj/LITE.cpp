#include <bits/stdc++.h>
using namespace std;



template <typename T>
class SegTree3{
private:
	T* tree;					/* tree pointer */
	T* d;						/* array used for lazy propagation */
	int n;						/* size of array which is used to build the segment tree */
	int h;						/* index of left most set bit */

	/* Helper function in build */
	void calc(int p, int k) {
		tree[p] = tree[p<<1] + tree[p<<1|1];				/* Add children */
		if(d[p]) tree[p] = k - tree[p];						/* Restore affect of d[p] as this d[p] didn't affect children yet */
	}
	/* add value*k to p */
	void apply(int p, int k) {
		tree[p] = k - tree[p];						/* Update value of node with value*k */
		if (p < n) d[p] = d[p]^1;						/* Update value of d[p] */
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
			for (int i = l >> s; i <= r >> s; ++i) if (d[i]) {
				apply(i<<1, k);
				apply(i<<1|1,k);
				d[i] = 0;
			}
	}
	/* increases all the values by value */
	void range_update(int l, int r, T value) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		int l0 = l, r0 = r, k = 1;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k <<= 1) {
			if (l&1) apply(l++, k);
			if (!(r&1)) apply(r--, k);
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
	/* Constructor which inintialize with 0, complexity - constant*/
	SegTree3<T>(int size):n(size){
		tree = new T[n<<1];
		d = new T[n];
		memset(tree,0,sizeof(T)*(n<<1));
		memset(d,0,sizeof(T)*(n));
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	/* Deconstructor */
	~SegTree3<T>(){
		delete[] tree;
		delete[] d;
	}
};

/*

*/



int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	SegTree3<int> b(n);
	while(q--){
		int f,l,r;
		cin>>f>>l>>r;
		if(!f) b.range_update(l-1,r-1,1);
		else cout<<b.range_query(l-1,r-1)<<endl;
	}
}