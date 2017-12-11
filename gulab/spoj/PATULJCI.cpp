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
typedef vector<pii> vpii;

typedef struct node{
	int candidate;
	int count;
}node;

node operator+(const node & a, const node & b){
	node temp;
	if(a.candidate == b.candidate){
		temp.candidate = a.candidate;
		temp.count = a.count + b.count;
	}
	else{
		if(a.count>b.count){
			temp.candidate = a.candidate;
			temp.count = a.count - b.count;
		}
		else{
			temp.candidate = b.candidate;
			temp.count = b.count - a.count;
		}
	}
	return temp;
}

class SegTree{
private:
	node* tree;
	int n;
public:
	node* get_Array(){
		return tree + n;
	}
	void build() {
		for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	node range_query(int l, int r) {
		node res;
		res.candidate = 0;
		res.count = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l&1) res = res + tree[l++];										/* if l is odd then apply func */
			if (!(r&1)) res = res + tree[r--];									/* if r is even then apply func */
		}
		return res;
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
	int n,c;
	cin>>n>>c;
	SegTree T(n);
	node *a = T.get_Array();
	vi v[100001];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].candidate;
		a[i].count = 1;
		v[a[i].candidate].pb(i);
	}
	T.build();
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		node temp = T.range_query(--l,--r);
		int x = upper_bound(all(v[temp.candidate]),r)-lower_bound(all(v[temp.candidate]),l);
		if(x>(r-l+1)/2)
			cout<<"yes "<<temp.candidate<<endl;
		else
			cout<<"no"<<endl; 
	}
	return 0;
}