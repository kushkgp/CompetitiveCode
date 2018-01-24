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
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

const int MOD = 1000000007;
const int K = 2;

typedef vector<vector<ll> > matrix;
matrix mul(matrix & a, matrix & b){
	assert(a[0].size()==b.size());
	matrix c(a.size(),vector<ll>(b[0].size(),0));
	FOR(i,a.size()) FOR(j,b[0].size()) FOR(k,b.size()){
		c[i][j] += (a[i][k]*b[k][j]);
		c[i][j]%=MOD;
	}
	return c;
}

void print(matrix & a){
	FOR(i,a.size()){
		FOR(j,a[0].size()){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int fastfib(matrix & T, matrix & f, ll n){
	matrix pw(T);
	FOR(i,K) FOR(j,K){
		if(i==j)
			T[i][j] = 1;
		else
			T[i][j] = 0;
	}
	while(n){
		if(n&1){
			T = mul(T,pw);
		}
		pw = mul(pw,pw);
		n>>=1;
	}
	f = mul(T,f);
	return f[K-1][0];
}


int main(){
	matrix f(K,vector<ll>(1,1));
	matrix T(K,vector<ll>(K,1));
	T[0][0] = 0;
	ll n;
	cin>>n;
	if(n<2){
		cout<<"1"<<endl;;
	}
	else{
		cout<<fastfib(T,f,n-1)<<endl;
	}
	return 0;
}