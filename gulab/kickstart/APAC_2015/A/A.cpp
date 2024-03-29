/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

bool ans(ll k, ll n){
	if(k==(n>>1))
		return 0;
	if(k < (n>>1))
		return ans(k,n>>1);
	return !ans(n-k,n>>1);
}

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		ll k;
		cin>>k;
		printf("Case #%d: %d\n", cnt++, ans(k,((ll)1)<<62));
	}
}