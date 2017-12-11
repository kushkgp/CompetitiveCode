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

template <typename T>
class BITree{
private:
	T *tree;
	int size;
public:
	T range_query(int idx){
		T sum = 0;
		idx++;
		for(;idx>0;idx -= (idx & -idx))
			sum = sum + tree[idx];
		return sum;
	}
	void point_update(int idx ,T val){
		idx++;
		for(; idx < size ; idx += (idx & -idx))
			tree[idx] = tree[idx] + val;
	}
	BITree<T>(int n){
		size = n+1;
		tree = new T[size];
		memset(tree,0,sizeof(T)*size);
		for (int i = 0; i < size ; ++i){
			this->point_update(i,1);
		}
	}
	~BITree<T>(){
		delete[] tree;
	}
};

int bs(BITree<int> & T,int n,int key){
	int x=-1;
	int mid,l=0,r=n-1;
	while(l<=r){
		mid=(l+r)/2;
		if(T.range_query(mid)>=key){
			x=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return x;
}

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi s(n);
		BITree<int> T(n);
		for (int i = 0; i < n; ++i)
			cin>>s[i];
		vi out;
		for (int i = n-1; i >= 0; --i)
		{
			int x = bs(T,n,s[i]+1);
			out.pb(n-x);
			T.point_update(x,-1);
		}
		reverse(all(out));
		for (int i = 0; i < n; ++i)
			cout<<out[i]<<" ";
		cout<<endl;
	}
	return 0;
}