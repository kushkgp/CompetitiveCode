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

ll phi[(int)1e7+1];
vi primes;
int n = 1e7;

int precompute(){
	memset(phi,0,sizeof(phi));
	primes.pb(2);
	F1(i,3,n){
		if(i%2==0)
			phi[i]=1;
		if(!phi[i]){
			primes.pb(i);
			for(int j=i;(ll)j*i<=n;j+=2){
				phi[j*i] = 1;
			}
		}
	}
}

int is_divisible(int k, vii &pa){
	F1(i,0,(int)pa.size()-1){
		ll expo=0;
		ll bs = pa[i].ff;
		// cout << bs << endl;
		while(bs<=k && expo<pa[i].ss){
			expo+=k/bs;
			bs*=pa[i].ff;
		}
		// cout << expo << " " << pa[i].ss << endl;
		if(expo<pa[i].ss)
			return 0;
	}
	return 1;
}

int binary_search(vii &pa){
	int l=1, r=n;
	int mid;
	while(l<r){
		mid=(l+r)/2;
		// cout << l << " " << r << " " << mid << endl;
		if(is_divisible(mid, pa)){
			// cout << "div" << endl;
			r = mid;
		}
		else{
			// cout << "Not div" << endl;
			l = mid+1;
		}
	}
	return l;
}

int main(){
	precompute();
	int a,b;
	cin >> a >> b;
	vii pa,p_b;
	F1(i,0,(int)primes.size()-1){
		int cnt=0,x=a;
		while(x%primes[i]==0)
			cnt++,x/=primes[i];
		if(cnt)
			pa.pb(mp(primes[i],cnt));
		cnt=0,x=b;
		while(x%primes[i]==0)
			cnt++,x/=primes[i];
		if(cnt)
			p_b.pb(mp(primes[i],cnt));
	}
	// cout << pa[0].ss << endl;
	// cout << binary_search(p_b) << " " << binary_search(pa) << endl;
	cout << max(binary_search(p_b) - binary_search(pa),0) << endl;
}