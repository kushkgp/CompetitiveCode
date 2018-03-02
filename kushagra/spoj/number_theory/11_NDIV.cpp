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

int phi[(int)1e5+1];
vi primes;

int precompute(int n){
	int k = sqrt(n)+1;
	memset(phi,0,sizeof(phi));
	F1(i,2,k){
		if(!phi[i]){
			// cout << i << endl;
			primes.pb(i);
			for(int j=i;(ll)j*i<=k;j++){
				phi[j*i]=1;
			}
		}
	}
	return 1;
}

int main(){
	int a,b,n;
	cin >> a >> b >> n;
	precompute(max(a,b));
	// cout << "done" << endl;
	int ans=0;
	F1(i,a,b){
		int n_div=1;
		int val=i;
		F1(j,0,(int)primes.size()-1){
			int expo=0;
			while(val%primes[j]==0)
				expo++,val/=primes[j];
			n_div*=(expo+1);
		}
		if(val!=1)
			n_div*=2;
		if(n_div==n)
			ans++;
	}
	cout << ans << endl;
}