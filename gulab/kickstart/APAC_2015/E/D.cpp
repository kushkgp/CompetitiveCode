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

int n;

int bs(int i, vi & A, int k){
	int l = 0, r = n - i, x = -1;
	while(l<=r){
		int mid = (l+r)>>1;
		if(A[i+mid]-A[i-1]<=k) x=mid, l=mid+1;
		else	r=mid-1;
	}
	return x+1;
}

inline ll no_of_subarr(vi & A, int k){
	ll ans = 0;
	F1(i,1,n)
		ans+=bs(i,A,k);
	return ans;
}

int bs2(vi & A, ll idx){
	int l = 0, r = 20000000, x;
	while(l<=r){
		int mid = (l+r)>>1;
		if(no_of_subarr(A,mid)>=idx) x=mid, r=mid-1;
		else	l=mid+1;
	}
	return x;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>n;
		int q;
		cin>>q;
		vi A(n+1);
		vector<ll> B(n+1);
		A[0] = B[0] = 0;
		F1(i,1,n){
			cin>>A[i];
			B[i] = (ll)(n-i+1)*A[i];
			A[i]+=A[i-1];
			B[i]+=B[i-1];
		}
		printf("Case #%d: \n", cnt++);
		while(q--){
			ll l,r;
			cin>>l>>r;
			ll ans = 0;
			int lsum = bs2(A,l-1);
			int rsum = bs2(A,r);
			ll rl = no_of_subarr(A,lsum);
			ll rr = no_of_subarr(A,rsum);
			ans+= (ll)lsum*(rl-l+1);
			ans-= (ll)rsum*(rr-r);
			F1(i,1,n){
				int idx1 = bs(i,A,lsum)-1;
				int idx2 = bs(i,A,rsum)-1;
				ans += (ll)(idx2-idx1)*(A[i+idx1]-A[i-1]);
				ans += B[i+idx2]-B[i+idx1]-(ll)(n-i-idx2)*(A[i+idx2]-A[i+idx1]);
			}
			cout<<ans<<endl;
		}
	}
}