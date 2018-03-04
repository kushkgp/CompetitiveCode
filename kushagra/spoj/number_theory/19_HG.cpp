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

bool phi[(int)1e5+1];
ll n = (int)1e5;
ll k;
int f=0;
vi primes;

int precompute(){
	fill(begin(phi),end(phi),false);
	phi[0]=phi[1]=1;
	F1(i,2,n){
		if(!phi[i]){
			primes.pb(i);
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i]=true;
			}
		}
	}
	return 1;
}
int compute(ll p, ll &ans){
	ll cnt=0;
	while(k%p==0)
		cnt++,k/=p;
	if(!cnt)
		return 1;
	ll cnt1=0;
	ll bs=p;
	while(n>=bs){
		cnt1+=(n/bs);
		if(bs>n/p)
			break;
		bs*=p; 
	}
	ans = min(ans, cnt1/cnt);
}

ll get_power(int &a, int b){
	ll ans=0;
	while(a%b==0 && a!=0)
		a/=b,ans++;
	return ans;
}

int compute(ll p, vi &a, vi &b, ll &ans){
	ll expo1=0, expo2=0;
	F1(i,0,(int)a.size()-1){
		expo1 += get_power(a[i], p);
	}
	F1(i,0,(int)b.size()-1){
		expo2 += get_power(b[i], p);
	}
	// cout << p << " " << expo1 << " " << expo2 << endl;
	expo1 = min(expo1, expo2);
	F1(i,0,expo1-1){
		ans*=p;
		if(ans>1e9)
			f=1;
		ans%=(ll)inf;
	}
	return ans;
}

int main(){
	precompute();
	int n,m;
	cin >> n;
	vi a(n);
	F1(i,0,n-1){
		cin >> a[i];
	}
	cin >> m;
	vi b(m);
	F1(i,0,m-1){
		cin >> b[i];
	}
	ll ans = 1;
	F1(i,0,primes.size()-1){
		compute(primes[i],a,b,ans);
		// cout << primes[i] << " " << ans << endl;
	}
	// cout << ans << endl;
	F1(i,0,n-1){
		if(a[i]!=1)
			compute(a[i],a,b,ans);
	}
	// cout << ans << endl;
	if(f)
		printf("%09d\n",(int)ans);
	else
		printf("%d\n",(int)ans);
}