/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

ll phi[(int)1e5+1];
vi primes;
int n = 1e5;

int precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,n){
		if(!phi[i]){
			primes.pb(i);
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i] = 1;
			}
		}
		phi[i]^=1;
	}
}

int main(){
	precompute();
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int l=2,r=2;
		int pl=1,pr=1;
		ll ans=0;
		if(k)
			F1(i,k-1,(int)primes.size()-1){
				if(primes[i]>n)
					break;
				int st=1;
				if(i>k-1)
					st = primes[i-k+1] - primes[i-k];
				ans+=(((ll)n-primes[i]+1)*st);
			}
		else{
			ans = (ll)(n-1)*(n-2);
			ans>>=1;
			ans+=(n-1);
		}
		cout << ans << endl;
	}
}