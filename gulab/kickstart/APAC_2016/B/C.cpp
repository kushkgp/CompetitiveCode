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
		ll n,a,b,c1,c2,x;
		ll lprev,rprev,l,r;
		cin>>n>>l>>r>>a>>b>>c1>>c2>>x;
		vector<pii> m(n<<1);
		F1(i,0,n-1){
			m[i<<1] = mp((int)min(l,r),i+1);
			m[(i<<1)|1] = mp((int)max(l,r)+1 ,-(i+1));
			lprev = l;
			rprev = r;
			l = ((a*lprev+b*rprev)%x + c1)%x;
			r = ((b*lprev+a*rprev)%x + c2)%x;
		}
		sort(all(m));
		vi maxe(n,0);
		set<int> s;
		int tot = 0, curr = 0;
		F1(i,0,(n<<1)-1){
			curr += m[i].ss>0?1:-1;
			if(m[i].ss>0)
				s.insert(m[i].ss-1);
			else
				s.erase(-m[i].ss-1);
			if(curr){
				tot += m[i+1].ff-m[i].ff;
				if(curr==1)
					maxe[(*s.begin())]+=m[i+1].ff-m[i].ff;
			}
		}
		int maxelement = 0;
		for(auto & it : maxe)
			maxelement = max(maxelement,it);
		printf("Case #%d: %d\n", cnt++, tot-(maxelement));
	}
}