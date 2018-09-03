#include<bits/stdc++.h>
using namespace std;

int n;

typedef struct node{
	int l, lc,r, rc, x, xc;
	struct node operator=(int a){
		l=r=x=a;
		lc=rc=xc=1;
		if(a==INT_MAX || a==INT_MIN){
			lc=rc=xc=0;	
		}
	}
} node;

node operator+(const node &a, const node &b){
	node ans;
	ans.l = a.l, ans.r = b.r;
	ans.lc = (b.l==a.l?a.lc+b.lc:a.lc);
	ans.rc = (b.r==a.r?a.rc+b.rc:b.rc);
	ans.xc = max(a.xc, b.xc);
	ans.x = a.xc > b.xc ? a.x : b.x;
	if(a.r==b.l && ans.xc < a.rc + b.lc){
		ans.x = a.r, ans.xc = a.rc + b.lc;
	}
	return ans;
}

void build(std::vector<node> &v){
	for(int i=n-1;i>0;i--)
		v[i]=v[i<<1]+v[i<<1|1];
}

int query(vector<node> &v, int l, int r){
	node pre, suf;
	pre = INT_MIN;
	suf = INT_MAX;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
		if(l&1)
			pre = pre + v[l++];
		if(!(r&1))
			suf = v[r--] + suf; 
	}
	return (pre+suf).xc;
}

int main(){
	while(1){
		int q;
		cin >> n;
		if(n==0)
			break;
		cin >> q;
		vector<node> num(2*n);
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			num[i+n]=x;
		}
		build(num);
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << query(num, --l, --r)<<endl;
		}
	}
}