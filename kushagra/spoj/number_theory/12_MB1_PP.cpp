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

int phi[(int)1e6+1];
int n = 1e6;
vi primes;
vi pp;

int is_palindrome(int a){
	string s2;
	string s = s2 = to_string(a);
	reverse(all(s));
	if(s==s2)
		return 1;
	return 0;
}
int get_prod(int a){
	int prod=1;
	while(a){
		if(a%10!=0)
			prod*=(a%10);
		a/=10;
	}
	return prod;
}
int precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,n){
		if(!phi[i]){
			primes.pb(i);
			if(is_palindrome(i))
				pp.pb(i);
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i]=1;
			}
		}
	}
	return 1;
}

int main(){
	precompute();
	// cout << pp.size() << endl;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << pp[n-1] << " " << primes[get_prod(pp[n-1])-1] << endl;
	}
}