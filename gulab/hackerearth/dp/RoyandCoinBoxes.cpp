#include <bits/stdc++.h>
using namespace std;




int n,m,q;
/*
Segment tree functions
for help see : http://codeforces.com/blog/entry/18051
*/
int *t; //global pointer for t 
void build() {  // build the tree parent = child1+child2 child to parent
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p+= n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

void update(int l,int r){	// update(add) only on parents lg(n)
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++]++;
    if (r&1) t[--r]++;
  }
}

void buildfromparent(){	// build from parent to child
	for (int i = 1; i < n; ++i){
		t[i<<1] +=t[i];
		t[i<<1|1] +=t[i];
	}
}

/*

*/

int main(){
	cin>>n>>m;
	int l,r,temp;
	temp = m;
	t = new int[2*n];
	for (int i = 0; i < 2*n; ++i)
		t[i]=0;

	while(m--){
		cin>>l>>r;
		update(l-1,r);
	}
	m = temp;
	int a[m+1];
	for (int i = 0; i <= m; ++i)
		a[i]=0;
	buildfromparent();
	for (int i = 0; i <n; ++i)
		a[t[i+n]]++;

	for (int i = m; i>0; --i)	// cumilative addition of ais from backward
		a[i-1]+=a[i];

	cin>>q;
	int search;
	while(q--){
		cin>>search;
		if (search>m)
			cout<<"0"<<endl;
		else
			cout<<a[search]<<endl;
	}
}