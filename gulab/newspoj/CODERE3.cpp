/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int bs(int *a,int n,int x){
	int l,r,m;
	l=0;
	r=n-1;
	int i=r;
	while(l<r){
		m=(l+r)/2;
		if(a[m]>=x){
			i=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return i;
}

int lis_f(const vi &a, vi& lis, int n){
	int b[n],maxlen=0;
	b[0]=a[0];
	lis[0]=1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]>b[maxlen]){
			b[++maxlen]=a[i];
			lis[i] = maxlen+1;
		}
		else{
			int x = bs(b,maxlen+1,a[i]);
			b[x]=a[i];
			lis[i] = x+1;
		}
	}
	return maxlen+1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		vi lis,lds;
		lis.resize(n);
		lds.resize(n);
		lis_f(v,lis,n);
		reverse(all(v));
		lis_f(v,lds,n);
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			m = max(m,lis[i]+lds[n-i-1]-1);
		}
		cout<<m<<endl;
	}
}