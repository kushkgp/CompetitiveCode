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

void add(ll & a, ll b){
	a+=b;
	if(a>1e18)
		a = 1e18+1;
}

int main(){
	vector<vector<ll> > f(202,vector<ll>(202,0));
	f[0][0]=1;
	F1(i,1,200)
		F1(j,0,i){
			add(f[i][j],f[i-1][j+1]);
			if(j)
				add(f[i][j],f[i-1][j-1]);
		}
	int t, cnt = 1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		string s;
		printf("Case #%d: ", cnt++);
		int dep = 0;
		if(k>f[n<<1][dep]) s = "Doesn't Exist!";
		else F2(rem,(n<<1),1){
			ll x = f[rem-1][dep+1];
			if(k<=x){
				dep++;
				s+="(";
			}
			else{
				k-=x;
				dep--;
				s+=")";
			}
		}
		cout<<s<<endl;
	}
}