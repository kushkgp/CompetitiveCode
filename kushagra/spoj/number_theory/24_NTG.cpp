/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007
#define MOD 1000000007

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
ll ans[(int)1e5+1];
ll prefix[(int)1e5+1];
int n = (int)1e5+1;
int k;


ll power(ll base, int expo){
	ll ans = 1;
	while(expo){
		if(expo&1)
			ans*=base;
		base*=base;
		base%=mod, ans%=mod;
		expo>>=1;
	}
	return ans;
}

int precompute(){
	fill(begin(phi),end(phi),0);
	fill(begin(ans),end(ans),0);
	ans[1]=1;
	F1(i,0,n){
		prefix[i] = power(i,k);
	}
	F1(i,2,n){
		if(!phi[i]){
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i]=i;
			}
			phi[i]=i-1;
		}
		else{
			int val1=1,val2=i;
			while(val2%phi[i]==0){
				val2/=phi[i],val1*=phi[i];
			}
			if(val2==1)
				phi[i] = (val1/phi[i])*phi[phi[i]];
			else
				phi[i] = phi[val1]*phi[val2];
		}
		for(int j=1;j<=n/i;j++){
			ans[i*j]+=((prefix[j]*(ll)phi[i])%mod);
			ans[i*j]%=mod;
		}
		ans[i]+=ans[i-1];
		ans[i]+=prefix[i];
		ans[i]%=mod;
	}
	return 1;
}

int main(){
	int t;
	cin >> k >> t;
	precompute();
	while(t--){
		int l,r;
		cin >> l >> r;
		cout << (ans[r] - ans[l-1] + mod)%mod << endl;
	}
}