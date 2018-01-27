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

void print(unsigned int a, int b){
	unsigned int c = 0, temp = a;
	string s;
	F2(j,3,0){
		c = 0; temp = a;
		temp>>=(j*8);
		F1(i,0,7)
			c+=(temp&(1<<i));
		s+=to_string(c);
		if(j)
			s+=".";
	}
	s+="/";
	s+=to_string(b);
	cout<<s<<endl;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<unsigned int,int> > v;
		F1(i,0,n-1){
			unsigned int a,b,c,d,p;
			scanf("%u.%u.%u.%u/%u", &a,&b,&c,&d,&p);
			unsigned int add = (a<<24)+(b<<16)+(c<<8)+d;
			add = add&((~0)<<(32-p));
			v.pb(mp(add,p));
		}
		asort(v);
		printf("Case #%d:\n", cnt++);
		set<pair<unsigned int,int> > s;
		F1(i,0,n-1){
			auto it = s.lower_bound(v[i]);
			if(s.size()){
				if(it!=s.begin()){
					it--;
					if(it->ff!=(v[i].ff&((~0)<<(32-it->ss))))
						s.insert(v[i]);
				}
			}
			else
				s.insert(v[i]);
		}
		int f = 1;
		set<pair<unsigned int,int> > m;
		while(f){
			f = 0;
			for(auto it = s.begin(); it!=s.end(); it++){
				m.insert(*it);
				if(it!=s.begin()){
					auto curr = it--;
					if(it->ss==curr->ss){
						if((it->ff|(1<<(32-it->ss)))==curr->ff){
							m.erase(*curr);
							m.erase(*it);
							m.insert(mp(it->ff,it->ss-1));
							f = 1;
						}
					}
					it = curr;
				}
			}
			s = m;
			m.clear();
		}
		for(auto & it : s)
			print(it.ff,it.ss);
	}
}