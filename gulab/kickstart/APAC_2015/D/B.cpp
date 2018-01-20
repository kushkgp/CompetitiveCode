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

int n,m,q;

bool func(vi & v, vpii & pos, int t){
	int tot = q;
	F1(i,0,n-1){
		if(!pos[i].ff) continue;
		int curr = inf;
		F1(j,0,m-1){
			if(!v[j]) continue;
			if(((v[j]>0)^(pos[i].ff>0)) && ((abs(pos[i].ff)+abs(v[j])-1)/abs(v[j])) <= t)
				curr = min(curr,abs(pos[i].ss-j));
		}
		if(curr>tot)
			return 0;
		tot-=curr;
	}
	return 1;
}

int BS(vi & v, vpii & pos){
	int l = 0, r = inf>>1;
	int x = -1;
	while(l<=r){
		int mid = (l+r)/2;
		if(func(v,pos,mid)){
			x = mid;
			r = mid-1;
		}
		else
			l = mid+1;
	}
	return x;
}

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		vi v(m);
		F1(i,0,m-1)
			cin>>v[i];
		vpii l(n);
		F1(i,0,n-1)
			cin>>l[i].ff>>l[i].ss;
		printf("Case #%d: ", cnt++);
		int ans = BS(v,l);
		if(ans==-1)
			cout<<"IMPOSSIBLE";
		else
			cout<<ans;
		cout<<endl;
	}
}