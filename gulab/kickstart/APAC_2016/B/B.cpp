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
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int a,b,k;
ll n;

// int power(int i, int p){
// 	int t = 1;
// 	while(p){
// 		if(p&1) p^=1,t=((ll)t*i)%k;
// 		else	p>>=1,t=((ll)t*t)%k;
// 	}
// 	return t;
// }

int power(int i, int p){
	if(!p)
		return 1%k;
	if(!i)
		return 0;
	int x = power(i,p>>1);
	x = ((ll)x*x)%k;
	if(p&1)
		return ((ll)x*i)%k;
	return x;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>a>>b>>n>>k;
		vector<ll> tot(k,(n/k));
		F1(i,1,n%k)
			tot[i]++;

		vector<ll> B(k,0);

		F1(i,0,k-1){
			int ind = power(i,b);
			B[ind]+=tot[i];
			B[ind]%=MOD;
		}

		int ans = 0;
		F1(i,0,k-1){
			int ind1 = power(i,a), ind2 = power(i,b);
			int x = tot[i];
			int y = B[(k-ind1)%k];
			ans+=((ll)x*y)%MOD;
			ans%=MOD;
			if((ind1+ind2)%k==0)
				ans = ((ans-tot[i])+MOD)%MOD;
		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
}