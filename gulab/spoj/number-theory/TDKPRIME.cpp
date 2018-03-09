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

#define N 90000000
int phi[N/64+1];
vi primes;
#define gP(n) (phi[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (phi[n>>6]&=~(1<<((n>>1)&31)))

void precompute()
{
	memset(phi,-1,sizeof(phi));
	primes.pb(2);
	for(int i = 3; i<=N; i+=2)
		if(gP(i)){
			primes.pb(i);
			for(int j = i; j <=N/i; j+=2) rP(i*j);
		}
}

int main(){
	precompute();
	int n;
	cin>>n;
	vpii q(n);
	F1(i,0,n-1){
		cin>>q[i].ff;
		q[i].ss = i;
	}
	sort(all(q));
	F1(i,0,n-1){
		q[i].ff = primes[q[i].ff-1];
		swap(q[i].ff,q[i].ss);
	}
	sort(all(q));
	F1(i,0,n-1)
		cout<<q[i].ss<<endl;
}