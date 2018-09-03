#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;

using vi = vector<int>;

typedef struct node {
	int ff, ss;
	node(){
		ff=0;
		ss=0;
	}
}node;

node operator+(const node &a, const node &b){
	node c;
	c.ff = a.ss < b.ss ? b.ff : a.ff;
	c.ss = (a.ff == b.ff ? a.ss + b.ss : abs(a.ss - b.ss));
	return c;
}

void build(vector<node> & v){
	int n = (v.size()>>1);
	for(int i=n-1;i>0;i--){
		v[i] = v[i<<1] + v[i<<1|1];
	}
}


int query(vector<node> & v, int l, int r){
	int n = (v.size()>>1);
	node ans;
	for(l+=n,r+=n;l<=r;(l>>=1),(r>>=1)){
		// cout<<l<<" "<<v[r].ff<<"::";
		if(l&1)
			ans = ans+v[l++];
		if(!(r&1))
			ans =  ans+v[r--];
		// cout<<ans.ff<<" "<<ans.ss<<endl;
	}
	return ans.ff;
}

int main(){
	int n,c;
	cin >> n >> c;
	vector<node> v(n<<1);
	vector<vector<int> > ind(c, vi());
	// cout << "sdgfdsghj\n\n" << endl;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		v[i+n].ff = --x;
		v[i+n].ss = 1;
		ind[x].pb(i);
	}
	build(v);
	int m;
	cin >> m;
	while(m--){
		int l,r;
		cin >> l >> r;
		int cand = query(v, --l, --r);
		// cout << "Re taken " << l << " " << r << " " << cand << endl;
		int a = upper_bound(ind[cand].begin(), ind[cand].end(), l-1) - ind[cand].begin()-1;
		int b = upper_bound(ind[cand].begin(), ind[cand].end(), r) - ind[cand].begin()-1;
		// cout << "req:" << ((r-l+1)>>1)+1 << " Got: " << b-a<<" "<< cand << endl;
		// cout << "sdfgdfgdf" << endl;
		if(b-a > ((r-l+1)>>1))
			cout << "yes " << (cand + 1)<< endl;
		else
			cout << "no" << endl;
		// cout << "return" << m << endl;
	}
	return 0;
}