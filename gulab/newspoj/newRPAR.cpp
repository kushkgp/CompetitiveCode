/*
 level h nodes are useless untill n is power of 2
 for sum and sum of squares using fuction(which computes the required sum) when needed
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 10007

int sum1(int a){			// sum1(a) = (1+2+3+....+a)%MOD
	ll x = ((ll)a)*(a+1);
	x>>=1;
	x%=MOD;
	return (int)x;
}
int sum2(int a){			// sum1(a) = (1^2+2^2+3^2+....+a^2)%MOD
	ll x = ((ll)a)*(a+1);
	x>>=1;
	x*=((a<<1)+1);
	x/=3;
	x%=MOD;
	return (int)x;
}

typedef struct p3{
 ll a,b,c;		// type is ll to force ll multiplication
} p3;

int *tree;
p3 *d;
int n,h;

p3 operator+(const p3 & a, const p3 & b){
	p3 temp;
	temp.a = (a.a + b.a)%MOD;
	temp.b = (a.b + b.b)%MOD;
	temp.c = (a.c + b.c)%MOD;
	return temp;
}

void setval(int p, p3 val, int k){
	int l = (p<<k) - 1;
	int r = l + (1<<k);
	l-=n;
	r-=n;
	/* always put + MOD as x%MOD-y%MOD can be -ve also */
	tree[p] += (val.a*(sum2(r)-sum2(l)+MOD) + val.b*(sum1(r)-sum1(l)+MOD) + val.c*((r-l)%MOD))%MOD;
	tree[p] %= MOD;
}
/* Helper function in build */
void calc(int p, int k) {
	tree[p] = tree[p<<1] + tree[p<<1|1];				/* Add children */
	tree[p] %= MOD;
	setval(p,d[p],k);						/* Restore affect of d[p] as this d[p] didn't affect children yet */
}
/* add value*k to p */
void apply(int p, p3 val , int k) {
	setval(p,val,k);						/* Update value of node with value*k */
	if(p<n) d[p] = d[p] + val;
}

/* Push values down in the range [l,r] */
void push(int l, int r) {
	int s = h, k = h-1;								
	for (l += n, r += n; s > 0; --s, k-- )
		for (int i = l >> s; i <= r >> s; ++i) {
			apply(i<<1,d[i], k);
			apply(i<<1|1,d[i],k);
			d[i].a=d[i].b=d[i].c=0;
		}
}

/* Build tree from children in [l,r] */
void build(int l, int r) {
	int k = 1;
	for (l += n, r += n; l > 1; k++) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i) calc(i,k);
	}
}

/* increases all the values by value */
void range_update(int l, int r, p3 val) {
	push(l, l);														/* Pushing everyone along root to leftmost */
	push(r, r);														/* Pushing everyone along root to rightmost */
	int l0 = l, r0 = r, k = 0;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1, k++ ) {
		if (l&1) apply(l++, val, k);								/* if l is odd then apply func */
		if (!(r&1)) apply(r--, val, k);								/* if r is even then apply func */
	}
	build(l0, l0);													/* building along r to root */
	build(r0, r0);													/* building along r to root */
}
/* Range Queries from l to r including both l and r */
int range_query(int l, int r) {
	push(l, l);														/* Pushing everyone along root to leftmost */
	push(r, r);														/* Pushing everyone along root to rightmost */
	int res = 0;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
		if (l&1) res += tree[l++],res%=MOD;								
		if (!(r&1)) res += tree[r--],res%=MOD;							
	}
	return res;
}

int main(){
	int q;
	cin>>n>>q;
	tree = new int[n<<1];
	d = new p3[n];
	memset(tree,0,sizeof(int)*(n<<1));
	memset(d,0,sizeof(p3)*n);
	h = sizeof(int) * 8 - __builtin_clz(n);
	while(q--){
		int f,l,r;p3 temp;
		cin>>f>>l>>r;
		if(!f) {cin>>temp.a>>temp.b>>temp.c;range_update(l,r,temp);}
		else cout<<range_query(l,r)<<endl;
	}
	delete[] tree;
	delete[] d;
	return 0;
}