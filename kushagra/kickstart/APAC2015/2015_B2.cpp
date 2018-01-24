/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

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
typedef vector<vpii> vvpii;


ll gcd(ll a, ll b){
	// if(a==0 && b==0)
	// 	return 1;
	if(b==0)
		return a;
	if(a<b){
		return gcd(b,a);
	}
	return gcd(b,a%b);
}


pii red(pii ok){
	int g = gcd(ok.ff, ok.ss);
	if(!g){
		cout << "======" << ok.ff << " " << ok.ss << endl;
	}
	return mp(ok.ff/g, ok.ss/g);
}


int main(){
	int t,C=1;
	cin >> t;
	while(t--){
		int p,e,t;
		cin >> p >> e >> t;
		vi ped(p), ext(e), tir(t);
		F1(i,0,p-1){
			cin >> ped[i];
		}
		F1(i,0,e-1){
			cin >> ext[i];
		}
		F1(i,0,t-1){
			cin >> tir[i];
		}
		map<pii,set<int> > rear;
		F1(i,0,e-1){
			F1(j,0,t-1){
				rear[red(mp(ext[i],tir[j]))].insert(ext[i]);
			}
		}
		int m;
		cin >> m;
		cout << "Case #" << C++ << ":"<< endl;
		while(m--){
			string ans="No";
			ll P,Q;
			cin >> P >> Q;
			ll g = gcd(P,Q);
			// cout << "jf" << endl;
			P = P/g;
			Q = Q/g;
			// cout << "kf" << endl;
			F1(i,0,p-1){
				F1(j,0,e-1){
					ll a,b;
					a = P*ext[j];
					b = Q*ped[i];
					ll g = gcd(a,b);
					a = a/g;
					b = b/g;
					// cout << P << " " << Q << " " << ext[j] << " " << ped[i] <<endl;
					// cout << a << " " << b <<  endl;
					if(!(a>inf || b >inf))
						if(rear.find(red(mp(a,b)))!=rear.end()){
							if(*rear[red(mp(a,b))].begin() != ext[j] ||  rear[red(mp(a,b))].size() > 1)
								ans = "Yes";
						} 
				}
			}

			cout << ans << endl;
		}
	}
}