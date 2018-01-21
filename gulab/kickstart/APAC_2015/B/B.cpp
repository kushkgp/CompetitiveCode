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

ll gcd(ll a, ll b){
	if(b>a)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int np,ne,nt;
		cin>>np>>ne>>nt;
		vi vp(np),ve(ne),vt(nt);
		for(int i = 0; i < np; i++)
			cin>>vp[i];
		for(int i = 0; i < ne; i++)
			cin>>ve[i];
		for(int i = 0; i < nt; i++)
			cin>>vt[i];
		map<pii,set<int> > e2;
		for(int i = 0; i < ne; i++)
			for(int j = 0; j < nt; j++){
				int g = gcd(ve[i],vt[j]);
				e2[mp(ve[i]/g,vt[j]/g)].insert(i);
			}
		vector<vector<pii> > e1(np,vector<pii>(ne));
		for(int i = 0; i < np; i++)
			for(int j = 0; j < ne; j++){
				int g = gcd(vp[i],ve[j]);
				e1[i][j] = mp(vp[i]/g,ve[j]/g);
			}
		printf("Case #%d:\n", cnt++);
		int m;
		cin>>m;
		while(m--){
			ll p,q;
			cin>>p>>q;
			ll g = gcd(p,q);
			p/=g;
			q/=g;
			int f = 0;
			for(int i = 0; i < np; i++)
				for(int j = 0; j < ne; j++){
					ll x = p*e1[i][j].ss;
					ll y = q*e1[i][j].ff;
					ll g = gcd(x,y);
					x/=g;
					y/=g;
					if(x!=(int)x || y!=(int)y)
						continue;
					pii req = mp((int)x,(int)y);
					if(e2.find(req)!=e2.end())
						if(e2[req].size()>1)
							f = 1;
						else if(*e2[req].begin()!=j)
							f=1;
				}
			if(f)
				cout<<"Yes";
			else
				cout<<"No";
			cout<<endl;
		}
	}
}