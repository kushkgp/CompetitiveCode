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
#define size1 
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
	}
	~BITree<T>(){
		delete[] tree;
	}
};


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi v;
		v.resize(n);
		int m = 0;
		int mi = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			m = max(m,v[i]);
			mi = min(mi,v[i]);
		}
		BITree<int> T(m-mi+1);
		ll result = 0;
		for (int i = n-1; i >=0 ; --i)
		{
			result+=T.range_query(v[i]-mi-1);
			T.point_update(v[i]-mi,1);
		}
		cout<<result<<endl;
	}
	return 0;
}