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
#define MOD 5000000
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

int give_ranks(vi & v, int n){
	vpii p;
	for (int i = 0; i < n; ++i)
		p.pb(mp(v[i],i));
	asort(p);
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		if(i&&p[i].ff!=p[i-1].ff)
			j++;
		v[p[i].ss] = j;
	}
	return j;
}

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
		return sum%MOD;
	}
	void point_update(int idx ,T val){
		idx++;
		for(; idx < size ; idx += (idx & -idx)){
			tree[idx] = tree[idx] + val;
			tree[idx]%=MOD;
		}
	}
	BITree<T>(int n){
		size = n+1;
		tree = new T[size];
		memset(tree,0,sizeof(T)*size);
	}
	void clear(){
		memset(tree,0,sizeof(T)*size);
	}
	~BITree<T>(){
		delete[] tree;
	}
};

int main(){
	int n,K;
	cin>>n>>K;
	vi v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	int maxrank = give_ranks(v,n);
	BITree<int> B(maxrank+1);
	vi dp(n);
	for (int i = 0; i < n; ++i)
		dp[i] = 1;
	for (int k = 1; k < K; ++k)
	{
		for (int i = 0; i < n; ++i){
			int temp = dp[i] - (B.range_query(v[i]) - B.range_query(v[i]-1));
			temp+=MOD;
			temp%=MOD;
			B.point_update(v[i], temp);
			dp[i] = B.range_query(v[i]-1);
		}
		B.clear();
	}
	vi check;
	check.resize(maxrank+1,0);
	int result=0;
	for (int i = n-1; i >=0; --i)
	{
		if(!check[v[i]]){
			result+=dp[i];
			result%=MOD;
			check[v[i]]=1;
		}
	}
	cout<<result<<endl;
	return 0;
}