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

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<long double> v(n);
		F1(i,0,n-1)
			cin>>v[i];
		sort(all(v));
		vector<long double> c(n);
		F1(i,0,n-1){
			c[i]=v[i];
			c[i]+= i?c[i-1]:0;		
		}
		long double ans = (long double)c[n-1]/n;
		F1(i,1,k){
			int x = upper_bound(all(v),ans)-v.begin();
			ans = (ans*x)/n+(c[n-1]-c[x-1])/n;
		}
		printf("Case #%d: %0.7LF\n", cnt++, ans);
	}
}