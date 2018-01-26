http://codeforces.com/blog/entry/18051

/*
 SegTree class	(Point modify/update and range query)
 To have point query and range update use differentiated array to build the tree
 modify - ln(n), range_query - ln(n) , construction from array - n
 space - 2*n
 op+ and op= should be defined on typename T
 you can change op+ for various functionalities(max,min,xor etc.)
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as sqrt<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

template <typename T>
class SegTree{
private:
	T* tree;					/* tree pointer */
	int n;						/* size of array which is used to build the segment tree */
public:
	/* get array to directly update in the array */
	/* note : there should be build() after all the modifications */
	T* get_Array(){
		return tree + n;
	}
	/* build the tree parent = child1+child2 child to parent */
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	/* set value at position p */
	void point_modify(int p, T value) {	
		for (tree[p+= n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];	/* p^1 gives sibling*/
	}
	/* inc by value at position p */
	void point_update(int p, T value) {	
		for (tree[p+=n] = tree[p+=n] + value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
	}
	/* Range Queries from l to r including both l and r */
	T range_query(int l, int r) {
		T res = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = res + tree[l++];										/* if l is odd then apply func */
			if (!(r&1)) res = res + tree[r--];									/* if r is even then apply func */
		}
		return res;
	}
	/* Constructor which copies from array, complexity - n */
	/* Here n denotes size of passed array */
	SegTree<T>(T * a, int size):n(size){
		tree = new T[n<<1];
		for (int i = 0; i < n; ++i)	tree[i+n] = a[i];
		this->build();
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	SegTree<T>(int size):n(size){
		tree = new T[n<<1];
		memset(tree,0,sizeof(T)*(n<<1));
	}
	/* Deconstructor */
	~SegTree<T>(){
		delete[] tree;
	}
};

/*

*/



/*
 SegTree2 class (range_update and range_queries on max,min etc.)
 point_modify/update - ln(n), range_update - ln(n) (lazy propagation), range_query - ln(n) , construction from array - n
 build(l,r) and push(l,r) - ln(n) + (r-l)
 space - 3*n (n extra space for lazy array)
 op+ and op= should be defined on typename T (op+ should be compatible with func passed)
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as sqrt<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

template <typename T>
class SegTree2{
private:
	T* tree;					/* tree pointer */
	T* d;						/* array used for lazy propagation */
	int n;						/* size of array which is used to build the segment tree */
	T identity;					/* identity element for func(like INT_MIN for max(int,int)) */
	int h;						/* index of left most set bit */
	const T & (*func) (const T &, const T &);		/* funcion to be passed */

	/* add value to p */
	void apply(int p, T value) {
		tree[p] = tree[p] + value;
		if (p < n) d[p] = d[p] + value;
	}
	/* build the tree parent = child1+child2 child to parent */
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i] = func(tree[i<<1],tree[i<<1|1]) + d[i];
	}
	/* Build all parent of node p bottom to top */
	void build(int p) {
		while (p > 1) p >>= 1, tree[p] = func(tree[p<<1], tree[p<<1|1]) + d[p];
	}
	/* push all updates downward along the path from root to p */
	/* can use push(p,p) also */
	void push(int p) {
		for (int s = h; s > 0; --s) {
			int i = p >> s;
			if (d[i] != 0) {
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
		}
	}
public:
	/* get array to directly update in the array */
	/* note : there should be push(l,r) before and build(l,r) after all the modifications */
	T* get_Array(){
		return tree + n;
	}
	/* Build tree from children in [l,r] */
	void build(int l, int r) {
		int k = 2;
		for (l += n, r += n-1; l > 1; k <<= 1) {
			l >>= 1, r >>= 1;
			for (int i = r; i >= l; --i) tree[i] = func(tree[i<<1],tree[i<<1|1]) + d[i];
		}
	}
	/* Push values down in the range [l,r] */
	void push(int l, int r) {
		int s = h, k = 1 << (h-1);
		for (l += n, r += n-1; s > 0; --s, k >>= 1)
			for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
	}
	/* set value at position p */
	void point_modify(int p, T value) {	
		for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = func(tree[p],tree[p^1]);
	}
	/* update value at position p */
	void point_update(int p, T value) {	
		for (tree[p += n] = tree[p+=n]+value; p > 1; p >>= 1) tree[p>>1] = func(tree[p],tree[p^1]);
	}
	/* increases all the values by value */
	void range_update(int l, int r, T value) {
		l += n, r += n;
		int l0 = l, r0 = r;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l&1) apply(l++, value);								
			if (!(r&1)) apply(r--, value);
		}
		build(l0);													/* building along r to root */
		build(r0);													/* building along r to root */
	}
	/* Range Queries from l to r including both l and r */
	T range_query(int l, int r) {
		T res = identity;
		l+=n;r+=n;
		push(l);												/* Pushing everyone along root to leftmost */
		push(r);												/* Pushing everyone along root to rightmost */
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = func(res,tree[l++]);					/* if l is odd then apply func */
			if (!(r&1)) res = func(res,tree[r--]);				/* if r is even then apply func */
		}
		return res;
	}
	/* Constructor which copies from array, complexity - n */
	/* Here n denotes size of passed array */
	SegTree2<T>(T * a, int size, const T & (*f)(const T &, const T &),T id = 0):n(size),func(f),identity(id){
		tree = new T[n<<1];
		d = new T[n];
		for (int i = 0; i < n; ++i)	tree[i+n] = a[i];
		memset(d,0,sizeof(T)*(n));
		this->build();
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	SegTree2<T>(int size, const T & (*f)(const T &, const T &),T id = 0):n(size),func(f),identity(id){
		tree = new T[n<<1];
		d = new T[n];
		for (int i = 0; i < n<<1; ++i)
			tree[i] = identity;
		memset(d,0,sizeof(T)*(n));
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	/* Deconstructor */
	~SegTree2<T>(){
		delete[] tree;
		delete[] d;
	}
};

/*

*/
/*
	Imp : Modification on interval [l, r] affects t[i] values only in the parents of border leaves: 
	l+n and r+n (except the values that compose the interval itself — the ones accessed in for loop).
	See http://codeforces.com/blog/entry/18051 or use pen and paper
*/

/*
 SegTree3 class	(Range update and range query)
 range_update - ln(n), range_query - ln(n) , construction from array - n
 space - 3*n
 op+, op*, op!= and op= should be defined on typename T
 you can change op+ for various functionalities(xor etc.)
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as sqrt<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

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
		if(d[p]) tree[p] = tree[p] + d[p] * k;				/* Restore affect of d[p] as this d[p] didn't affect children yet */
	}
	/* add value*k to p */
	void apply(int p, T value, int k) {	
		tree[p] = tree[p] + value*k;						/* Update value of node with value*k */
		if (p < n) d[p] = d[p] + value;						/* Update value of d[p] */
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
	/* increases all the values by value */
	void range_update(int l, int r, T value) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		int l0 = l, r0 = r, k = 1;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k <<= 1) {
			if (l&1) apply(l++, value, k);
			if (!(r&1)) apply(r--, value, k);
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
	SegTree3<T>(T * a, int size):n(size){
		tree = new T[n<<1];
		d = new T[n];
		for (int i = 0; i < n; ++i)	tree[i+n] = a[i];
		memset(d,0,sizeof(T)*(n));
		this->build(0,n-1);
		h = sizeof(int) * 8 - __builtin_clz(n);
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


/*
 SegTree4 class	(Range modify and range query)
 range_modify - ln(n), range_query - ln(n) , construction from array - n
 space - 3*n
 op+, op*, op!= and op= should be defined on typename T
 you can change op+ for various functionalities(xor etc.)
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as sqrt<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

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
	/* increases all the values by value */
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

// variation of segment tree where k is used as a level(leaf level is 0) 
// to use it change apply and calc accordingly(see notes) and delete the redundant code according to the problem
// used in DCEPC11I
// For square sum or sum see spoj/newRPAR.cpp

class SegTree5{
private:
	ll* tree;					/* tree pointer */
	pill * d;					/* array used for lazy propagation */
	int n;						/* size of array which is used to build the segment tree */
	int h;						/* index of left most set bit */
	void apply_val(int p, pill value, int k){
		int t = value.ff;
		tree[p] += t*(sum1(1<<k));
		tree[p] += value.ss*(1<<k);
	}
	void calc(int p, int k) {
		tree[p] = tree[p<<1] + tree[p<<1|1];				/* Add children */
		if(d[p].ff) apply_val(p,d[p],k);					/* Restore affect of d[p] as this d[p] didn't affect children yet */
	}
	void apply(int p, pill value, int k) {	
		apply_val(p,value,k);								/* Update value of node with value*k */
		if (p < n) d[p].ff+=value.ff, d[p].ss+=value.ss;	/* Update value of d[p] */
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
				d[i].ss += d[i].ff*(1<<k);
				apply(i<<1|1, d[i], k);
				d[i].ff = d[i].ss = 0;
			}
	}
	void range_update(int l, int r) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		pii lval,rval;
		lval.ff = rval.ff = 1;
		lval.ss = 0;
		rval.ss = r-l;
		int l0 = l, r0 = r, k = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k++) {
			if (l&1) apply(l++, lval, k), lval.ss+=(1<<k);				/* if l is odd then apply func */
			if (!(r&1)) apply(r--, rval, k),rval.ss-=(1<<(k+1));		/* if r is even then apply func */
			else rval.ss-=(1<<k);
		}
		build(l0, l0);													/* building along r to root */
		build(r0, r0);													/* building along r to root */
	}
	ll range_query(int l, int r) {
		push(l, l);														/* Pushing everyone along root to leftmost */
		push(r, r);														/* Pushing everyone along root to rightmost */
		ll res = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = res + tree[l++];								
			if (!(r&1)) res = res + tree[r--];
		}
		return res;
	}
	SegTree5(int size):n(size){
		tree = new ll[n<<1];
		d = new pill[n];
		memset(tree,0,sizeof(ll)*(n<<1));
		memset(d,0,sizeof(pill)*(n));
		h = sizeof(int) * 8 - __builtin_clz(n);
	}
	~SegTree5(){
		delete[] tree;
		delete[] d;
	}
};

/*

*/