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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll power(ll a, ll b){
	ll ans = 1;
	while(b>0){
		if(b&1){
			ans*=a;
			ans%=MOD;
		}
		b>>=1;
		a=(a*a)%MOD;
	}
	return ans;
}


int main(){
	int t, cnt =1;
	cin>>t;
	while(t--){
		int n;
		ll ans = 0;
		cin>>n;
		int a;
		F1(i,0,n-1){
			cin>>a;	
			ans+=(((power(2,i)-power(2,n-1-i)+MOD)%MOD)*a)%MOD;
			ans=(ans+MOD)%MOD;
		}
		printf("Case #%d: %lld\n", cnt++, ans);
	}
}