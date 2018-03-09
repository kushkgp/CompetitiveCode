/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef v<pii> vpii;

class BIT{
	vi A;
	int n;
public:
	BIT(int x):n(x){
		A.resize(n+1,0);
	}
	void point_update(int i, int f){
		for(; i<=n; i+=i&(-i))
			A[i]+=f;
	}
	int range_query(int idx){
		int ans = 0;
		for(int i = idx; i>0; i-=i&(-i))
			ans+=A[i];
		return ans;
	}
};

int main(){
	int n,p;
	cin>>n>>p;
	vi a(n);
	BIT T(n);
	vi A(n);
	F1(i,0,n-1){
		cin>>A[i];
		a[i] = A[i];
	}

	sort(all(A));
	F1(i,0,n-1){
		int idx = lower_bound(all(A),a[i])-A.begin();
		a[i] = idx+1;
	}

	ll x = 0, ans = -1;
	int idx = 0;
	F1(i,0,n-1){
		if(i>=p){
			x-=T.range_query(a[i-p]-1);
			T.point_update(a[i-p],-1);
		}
		x+=T.range_query(n)-T.range_query(a[i]);
		T.point_update(a[i],1);
		if(ans<x)
			ans = x, idx = i-p+2;
	}
	cout<<idx<<" "<<ans<<endl;
}