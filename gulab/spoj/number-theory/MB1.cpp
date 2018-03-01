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

#define N 10000000
bool phi[10000001];
vi primes, pp;

bool palindrome(int a){
	string s = to_string(a);
	F1(i,0,(s.length()-1)/2)
		if(s[i]!=s[s.length()-i-1])
			return false;
	return true;
}

void precompute(){
	fill(begin(phi), end(phi), 0);
	F1(i,2,N){
		if(!phi[i]){
			primes.pb(i);
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = 1;
		}
	}
	F1(i,0,primes.size()-1)
		if(palindrome(primes[i]))
			pp.pb(primes[i]);
}

int prod(int a){
	string s = to_string(a);
	int ret = 1;
	F1(i,0,s.length()-1)
		if(s[i]!='0')
			ret*=(s[i]-'0');
	return ret;
}

int main(){
	BOOST;
	precompute();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<pp[n-1]<<" "<<primes[prod(pp[n-1])-1]<<endl;
	}
}