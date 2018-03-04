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

bool phi[(int)1e4+1];
int n = (int)1e4+1;
int k;
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
int compute(int p, int &ans){
	int cnt=0;
	while(k%p==0)
		cnt++,k/=p;
	if(!cnt)
		return 1;
	int cnt1=0;
	int bs=p;
	while(n>=bs){
		cnt1+=(n/bs);
		if(bs>(double)n/p)
			break;
		bs*=p; 
	}
	ans = min(ans, cnt1/cnt);
}
int get_answer(int &ans){
	ans=INT_MAX;
	F1(i,0,(int)primes.size()-1 && primes[i]<=k){
		compute(primes[i],ans);
	}
	if(k!=1){
		compute(k,ans);
	}
	return ans;
}

int main(){
	precompute();
	int t;
	cin >> t;
	int ans;
	int C=1;
	while(t--){
		cin >> n >> k;
		cout << "Case " << C++ << ": " << get_answer(ans) << endl;
	}
}