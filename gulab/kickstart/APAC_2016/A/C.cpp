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
int m;
vi c;

long double compute(long double x){
	long double ans  = c[m];
	long double temp = x;
	F2(i,m-1,1){
		ans+=c[i]*temp;
		temp*=x;
	}
	ans-=(c[0])*temp;
	return ans;
}

long double bs(){
	ll l = 0, r = 2*1e11;
	long double x = 15;
	while(l<=r){
		ll mid = (l+r)>>1;
		if(compute((long double)mid/1e10)<0){
			x = (long double)mid/1e10;
			r = mid-1;
		}
		else
			l = mid+1;
	}
	return x;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>m;
		c.clear();
		c.resize(m+1);
		F1(i,0,m)
			cin>>c[i];
		printf("Case #%d: %.12LF\n", cnt++, bs()-1);
	}
}