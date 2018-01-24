#include <bits/stdc++.h>
#define size 131073
#define size1 262145
using namespace std;

int t0[size1],t1[size1],t2[size1],d[size];
int h,n;

void rotate(int p, int val){
	int x,y,z;
	x = t0[p];
	y = t1[p];
	z = t2[p];
	if(val==1){
		t0[p] = z;
		t1[p] = x;
		t2[p] = y;
	}
	else if(val==2){
		t0[p] = y;
		t1[p] = z;
		t2[p] = x;
	}
}

inline void allt(int p){
	t0[p] = t0[p<<1]+t0[p<<1|1];
	t1[p] = t1[p<<1]+t1[p<<1|1];
	t2[p] = t2[p<<1]+t2[p<<1|1];
}

void apply(int p,int val){
	if(p<n)
		d[p] = (d[p]+val)%3;
	rotate(p,val);
}

void calc(int p){
	allt(p);
	rotate(p,d[p]);
}

void push(int p){
	for (int s = h ; s > 0; s--)
	{
		int i = p>>s;
		if(d[i]){
			apply(i<<1,d[i]);
			apply(i<<1|1,d[i]);
			d[i]=0;
		}
	}
}


void build(int p){
	while(p>1) p>>=1, calc(p);
}
void build(){
	for (int i = n-1; i > 0;--i) t0[i]= t0[i<<1] + t0[i<<1|1];
}

void range_update(int l,int r){
	l+=n;
	r+=n;
	int l0 = l,r0 = r;
	push(l);
	push(r);
	for(;l<=r;l>>=1,r>>=1){
		if(l&1) apply(l++,1);
		if(!(r&1)) apply(r--,1);
	}
	build(l0);
	build(r0);
}

int range_query(int l,int r){
	l+=n;
	r+=n;
	push(l);
	push(r);
	int res=0;
	for(;l<=r;l>>=1,r>>=1){
		if(l&1) res+=t0[l++];
		if(!(r&1)) res+=t0[r--];
	}
	return res;
}

int main(){
	int q;
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n>>q;
	h = sizeof(int) * 8 - __builtin_clz(n);

	for (int i = 0; i < n; ++i)
	{
		t0[i+n]=1;
	}
	memset(t1,0,sizeof(int)*(n<<1));
	memset(t2,0,sizeof(int)*(n<<1));
	memset(d,0,sizeof(int)*(n));
	build();
	while(q--){
		int f,a,b;
		cin>>f>>a>>b;
		if(f){
			cout<<range_query(a,b)<<endl;
		}
		else
			range_update(a,b);
	}
}