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
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vi a(n),b(n),c(n),d(n);
		F1(i,0,n-1)
			cin>>a[i];
		F1(i,0,n-1)
			cin>>b[i];
		F1(i,0,n-1)
			cin>>c[i];
		F1(i,0,n-1)
			cin>>d[i];
		map<int,int> m1,m2;
		F1(i,0,n-1)
			F1(j,0,n-1){
				if(m1.find(a[i]^b[j])==m1.end())
					m1[a[i]^b[j]]=0;
				m1[a[i]^b[j]]++;
			}
		F1(i,0,n-1)
			F1(j,0,n-1){
				if(m2.find(c[i]^d[j])==m2.end())
					m2[c[i]^d[j]]=0;
				m2[c[i]^d[j]]++;
			}
		ll ans = 0;
		for(auto & it : m1){
			int x = it.ff;
			int y = x^k;
			if(m2.find(y)!=m2.end())
				ans+=(ll)it.ss*m2[y];
		}
		printf("Case #%d: %lld\n", cnt++, ans);
	}
}