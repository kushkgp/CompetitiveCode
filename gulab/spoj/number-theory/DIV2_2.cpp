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

#define N 1000000
int phi[1000001];

void precompute(){
	memset(phi,0,sizeof(phi));
	int tot = 0;
	F1(i,2,N){
		if(!phi[i])
			for(int j = 2; (ll)j*i<=N; j++){
				if(!phi[i*j]) phi[i*j] = 1;
				if(!(j%i)) phi[i*j] = 2;
			}
			
		tot+=(phi[i]==1);
		if(phi[i]==1 && !(tot%108))
			cout<<i<<endl;
	}
	
}
/* only true for numbers with powers of primes == 1 in prime factorization*/
int main(){
	BOOST;
	precompute();
}