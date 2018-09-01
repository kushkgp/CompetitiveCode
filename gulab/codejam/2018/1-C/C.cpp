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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		v<ll> a(n);
		F1(i,0,n-1){
			cin>>a[i];
		}
		reverse(all(a));
		v<ll> b(n+1,-1);
		b[0] = 1e12;
		F1(i,0,n-1){
			int start_ind = n+1 - (upper_bound(allr(b),-1) - b.rbegin());
			int end_ind = n+1 - (upper_bound(allr(b),6*a[i]) - b.rbegin());
			// cout<<start_ind<<" "<<end_ind<<endl;
			F2(j,start_ind,end_ind){
				b[j] = max(b[j],min(b[j-1]-a[i],6*a[i]));
			}
		}
		int f = 0;
		F2(i,n,1){
			if(b[i]>=0){
				f = i;
				break;
			}
		}
		printf("Case #%d: %d\n", cnt++, f);
	}
}