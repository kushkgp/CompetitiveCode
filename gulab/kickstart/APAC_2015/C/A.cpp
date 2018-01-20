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


int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
		vi points(p);
		for(int i = 0; i < p; i++)
			cin>>points[i];
		int n;
		cin>>n;
		map<string,priority_queue<int> > m;
		for(int i = 0; i < n; i++){
			int w;
			cin>>w;
			for(int j = 0; j < p; j++){
				string s;
				cin>>s;
				m[s].push(w*points[j]);
			}
		}
		vector<pair<int,string> > v;
		int k;
		cin>>k;
		for(auto & it : m){
			string s = it.ff;
			int val = 0, tot = 0;
			while(!it.ss.empty() && tot<k){
				val+=it.ss.top();
				it.ss.pop();
				tot++;
			}
			v.pb(mp(0-val,s));
		}
		asort(v);
		printf("Case #%d:\n", cnt++);
		int rank = 0, offset = 0;
		int prev = INT_MAX;
		for(int i = 0; i < v.size(); i++){
			if(v[i].ff!=prev){
				prev = v[i].ff, rank+=offset;
				rank++, offset=0;
			}
			else offset++;
			printf("%d: %s\n", rank, v[i].ss.c_str());
		}
	}
}