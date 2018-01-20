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


void build(vector<double> & a, vi & level, int n){
	for(int i = n-1; i > 0; i--){
		a[i] = pow(a[i<<1]*a[i<<1|1],0.5);
		level[i] = level[i<<1]+1;
	}
}

double query(int l, int r, vector<double> & a, vi & level, int n){
	double d = r-l+1;
	double ans = 1;
	l+=n,r+=n;
	for(;l<=r;l>>=1,r>>=1){
		if(l&1){
			ans*=pow(a[l],(1<<level[l])/d);
			l++;
		}
		if(!(r&1)){
			ans*=pow(a[r],(1<<level[r])/d);
			r--;
		}
	}
	return ans;
}

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<double> a(1+(n<<1));
		vi level(1+(n<<1),0);
		for(int i = 0; i < n; i++)
			cin>>a[i+n];
		printf("Case #%d:\n",cnt++);
		build(a,level,n);
		while(m--){
			int l,r;
			cin>>l>>r;
			printf("%0.9lf\n", query(l,r,a,level,n));
		}
	}
}